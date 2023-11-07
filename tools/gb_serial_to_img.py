from datetime import datetime
from os import remove
import numpy as np             # pip install numpy
from PIL import Image          # pip install pillow
import serial                  # pip install pyserial

COM_PORT = "COM3"
BAUDRATE = 9600
KEEP_TEMP_FILE = True

ser = serial.Serial(COM_PORT,baudrate=BAUDRATE)
with open("./gbcomm.2bpp","wb") as f:
    for _ in range(5760):
        f.write(ser.read(1))
        
infile = open("./gbcomm.2bpp", "rb")
imgbuffer = np.zeros((144,160), dtype="uint8")
for r in range(18):
    for c in range(20):
        tile = infile.read(16)
        for tr in range(8):
            low_bits = tile[tr * 2]
            high_bits = tile[(tr * 2) + 1]
            
            for tc in range(8):
                colorindex = 0
                mask = (0b10000000 >> tc)

                if ((high_bits & mask) == mask):
                    colorindex |= 0b00000010
                if ((low_bits & mask) == mask):
                    colorindex |= 0b00000001
                    
                imgbuffer[r * 8 + tr][c * 8 + tc] = colorindex;

infile.close()
if not KEEP_TEMP_FILE:
    remove("./gbcomm.2bpp")
    
imgbuffer = imgbuffer * 85
imgbuffer = 255 - imgbuffer
img = Image.fromarray(imgbuffer, mode ="L")

now = datetime.now()
dt_string = now.strftime("%Y%m%d_%H%M%S")
bmp_name = "gbimg_" + dt_string + ".bmp"
img.save(bmp_name, "BMP")
