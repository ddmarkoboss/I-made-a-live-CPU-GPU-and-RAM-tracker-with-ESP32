import psutil
import GPUtil
import serial
import time

ser = serial.Serial('COM3', 115200) #change to your ESP32's COM port
time.sleep(2)

try:
    while True:
        cpu = int(psutil.cpu_percent())
        ram = int(psutil.virtual_memory().percent)
        
        # Get GPU load
        gpus = GPUtil.getGPUs()
        gpu = int(gpus[0].load * 100) if gpus else 0
        
        # Send clean string
        data = f"{cpu}%,{ram}%,{gpu}%\n"
        ser.write(data.encode('utf-8'))
        time.sleep(1)
except KeyboardInterrupt:
    ser.close()
