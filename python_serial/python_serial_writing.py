import time

import serial as sr
port  = 'COM3'
baud_rate = 9600

arduinoData = sr.Serial(port, baud_rate)

while True:
    arduinoData.write(bytes('1', 'utf-8')) #  "bytes" function to encode the string which is "1"  
    time.sleep(0.5) # sleep function to make delay between the statments 
    arduinoData.write(bytes('0', 'utf-8'))
    time.sleep(0.5)
