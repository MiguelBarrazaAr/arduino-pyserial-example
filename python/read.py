from time import sleep
from serial import Serial

# modificar por el puerto correcto
port = 'COM6'

ser = Serial(port, 9600, timeout=0.2)
print("port conect: ", ser.name)

try:
    while True:
        rawString = ser.readline()
        text = rawString.decode()
        if text:
            print(text)
except KeyboardInterrupt:
    ser.close()
    print("port arduino closed")
