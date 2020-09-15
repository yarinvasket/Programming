import socket

def main():
    # Create a client socket:
    my_socket = socket.socket()
    my_socket.connect(("127.0.0.1", 8820))

    # Send data to server
    name = input("Please enter your name: ")
    my_socket.send(name.encode('ascii'))

    # Get data from server
    data = my_socket.recv(1024)
    print("The server sent: " + data.decode('ascii'))

    # Close the socket:
    my_socket.close()

if __name__ == "__main__":
    main()