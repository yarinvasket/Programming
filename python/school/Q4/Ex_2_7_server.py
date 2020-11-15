#   Ex. 2.7 template - server side
#   Author: Barak Gonen, 2017
#   Modified for Python 3, 2020

import socket
from PIL import ImageGrab
from pathlib import Path
import os.path

IP = '0.0.0.0'
PORT = 9840


def receive_client_request(client_socket):
	"""Receives the full message sent by the client

	Works with the protocol defined in the client's "send_request_to_server" function

	Returns:
		command: such as DIR, EXIT, SCREENSHOT etc
		params: the parameters of the command

	Example: 12DIR c:\cyber as input will result in command = 'DIR', params = 'c:\cyber'
	"""

	data = client_socket.recv(1024).decode().split()
	command = data[0]
	if len(data) <= 1:
		params = None
	else:
		params = data[1::]

	return command, params


def check_client_request(command, params):
	"""Check if the params are good.

	For example, the filename to be copied actually exists

	Returns:
		valid: True/False
		error_msg: None if all is OK, otherwise some error message
	"""
	if command == 'SEND_FILE':
		return os.path.isfile(params[0]), 'Success'
	return True, 'Failure'


def handle_client_request(command, params):
	"""Create the response to the client, given the command is legal and params are OK

	For example, return the list of filenames in a directory

	Returns:
		response: the requested data
	"""
	if command == 'TAKE_SCREENSHOT':
		im = ImageGrab.grab()
		im.save(r'Files\screen.png')
		return 'screenshot taken'
	elif command == 'SEND_FILE':
		return params

def send_response_to_client(command, response, client_socket):
	"""Create a protocol which sends the response to the client

	The protocol should be able to handle short responses as well as files
	(for example when needed to send the screenshot to the client)
	"""
	if command == 'SEND_FILE':
		path = response[0]
		f = open(path, 'rb')
		bytesize = Path(path).stat().st_size
		packets = str(int(bytesize / 2048 + 1))
		client_socket.send(packets.encode())
		l = f.read(2048)
		while (l):
			client_socket.send(l)
			l = f.read(2048)
	else:
		client_socket.send(response.encode())


def main():
	# open socket with client
	server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	server_socket.bind((IP, PORT))
	server_socket.listen()
	client_socket, address = server_socket.accept()

	# handle requests until user asks to exit
	while True:
		command, params = receive_client_request(client_socket)
		valid, error_msg = check_client_request(command, params)
		if valid:
			response = handle_client_request(command, params)
			send_response_to_client(command, response, client_socket)
		else:
			send_response_to_client(error_msg, client_socket)

		if command == 'EXIT':
			break

	client_socket.close()
	server_socket.close()

if __name__ == '__main__':
	main()