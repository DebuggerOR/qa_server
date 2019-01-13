import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
dest_ip = '127.0.0.1'
dest_port = 5300

s.connect((dest_ip, dest_port))
msg = raw_input("Message to send: ")
while not msg == 'end':
    s.send(msg)
    msg = raw_input("Message to send: ")
s.send(msg)
s.close()