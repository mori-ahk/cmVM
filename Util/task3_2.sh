avr-gcc -Os -Wall -DF_CPU=16000000UL -mmcu=atmega328p -DonTarget ../Tests/tvmstack.c ../HAL/hal.c ../HAL/out.c ../VM\ stack/vmstack.c ../BSL/_cout.c ../BSL/_xtoa.c -o _cout.o

avr-objcopy -O ihex -j .text -j .data _cout.o  _cout.hex

avrdude -c arduino -p atmega328p -b 57600 -P $1 -D -Uflash:w:_cout.hex:i

# deleting hex and object file after we are done with them
rm -rf *.hex *.o