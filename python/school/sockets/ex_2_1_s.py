import socket

s = socket.socket()
s.bind(('127.0.0.1', 8820))

s.listen(1)

c, addr = s.accept()

cname = c.recv(1024)
c.send(cname)

c.close()
s.close()