import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
dest_ip = '127.0.0.1'
dest_port = 5108

s.connect((dest_ip, dest_port))
msg = raw_input("Message to send: ")
while not msg == 'end':
    s.send(msg+"\n")
    msg = raw_input("Message to send: ")
s.send(msg+"\n")
data = s.recv(4096)
print "Server sent: ", data
s.close()
