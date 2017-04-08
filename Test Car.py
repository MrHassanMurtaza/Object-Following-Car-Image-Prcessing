import serial

ser = serial.Serial('COM10', 9600)

while True:
    x = input("enter number");
    ser.write(str(x));
