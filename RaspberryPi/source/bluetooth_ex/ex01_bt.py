from bluetooth import *

LINE_END = "\r\n"

client_socket=BluetoothSocket( RFCOMM )
client_socket.connect(("00:18:91:D7:38:45", 1))

try:
    while True:
        msg=input("Send : ")+LINE_END
        client_socket.send(msg)

        msg = client_socket.recv(1024)
        print(f"received message : {msg}")

except KeyboardInterrupt:
    print("Finished")

client_socket.close()

