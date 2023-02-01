import serial
from time import sleep
import sys
from threading import Thread
class Arduino:
    def __init__(self) -> None:
        try:       
            self.connection = serial.Serial("/dev/ttyUSB0",115200,timeout=1)
            self.value = [0,0,0]
        except serial.SerialException:
            print("Serial device not connected")
            sys.exit(1)
    def read_values(self,freq=.5):
        while 1:
            sleep(freq)
            self.value_raw = self.connection.readline().decode().split(",")
            if len(self.value_raw)>1:
                self.value = [x.split(":")[1] for x in self.value_raw]
                self.value[2] = self.value[2].strip("\r\n")
                print(self.value)
if __name__ == "__main__":
    ard = Arduino()
    Thread(target=ard.read_values).start()
    while True:
        print("i")
        sleep(0.5)