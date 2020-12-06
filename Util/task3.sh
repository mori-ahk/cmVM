avr-gcc -Os -Wall -DF_CPU=16000000UL -mmcu=atmega328p -DDebugBSL -DonTarget ../BSL/_cout.c ../BSL/_xtoa.c -o _cout.o

avr-objcopy -O ihex -j .text -j .data _cout.o  _cout.hex

avrdude -c arduino -p atmega328p -b 57600 -P $1 -D -Uflash:w:_cout.hex:i

