avr-gcc -Os -Wall -DF_CPU=16000000UL -mmcu=atmega328p -DonTarget ../BSL/_TestIOReg0.c ../BSL/_IOReg.c ../HAL/hal.c ../HAL/out.c ../BSL/_cout.c ../BSL/_xtoa.c -o TestIOReg.o

avr-objcopy -O ihex -j .text -j .data TestIOReg.o  TestIOReg.hex

avrdude -c arduino -p atmega328p -b 57600 -P $1 -D -Uflash:w:TestIOReg.hex:i