from time import sleep
from serial import Serial

# modificar por el puerto correcto
port = 'COM6'

ser = Serial(port, 9600)
print("port conect: ", ser.name)
sleep(1.6)
for x in range(4):
    ser.write(b'music')
    sleep(0.7)
ser.close()
print("fin")