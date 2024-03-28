import serial
import time

ser = serial.Serial('/dev/tty.HC-05', 9600)
time.sleep(2)  # Wait for the connection to establish

try:
    while True:
        direction = input("Enter direction: ")
        if direction == "f" or direction == "b" or direction == "l" or direction == "r":
            ser.write(direction.encode())
            time.sleep(0.1)  
except KeyboardInterrupt:
    print("Program terminated")
    ser.close()  # Close the serial connection when done
