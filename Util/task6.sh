avr-gcc -Os -Wall -DF_CPU=16000000UL -mmcu=atmega328p -DonTarget ../HAL/TestInterman.c ../HAL/interman.c ../HAL/hal.c ../HAL/out.c ../BSL/_cout.c ../BSL/_xtoa.c -o TestInterman.o

avr-objcopy -O ihex -j .text -j .data TestInterman.o  TestInterman.hex

avrdude -c arduino -p atmega328p -b 57600 -P /dev/cu.usbserial-14310 -D -Uflash:w:TestInterman.hex:i