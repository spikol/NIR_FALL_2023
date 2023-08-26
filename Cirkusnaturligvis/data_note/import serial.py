#import serial

#ser = serial.Serial('COM5')  # replace 'COM4' with your port
#print(ser)

import serial.tools.list_ports

def list_serial_ports():
    ports = serial.tools.list_ports.comports()
    for port in ports:
        print(port)

if __name__ == '__main__':
    list_serial_ports()