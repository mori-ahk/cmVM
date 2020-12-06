avr-gcc -Os -Wall -DF_CPU=16000000UL -mmcu=atmega328p -DonTarget ../VM\ Core/_admin.c ../VM\ Core/vm.c ../HAL/out.c ../HAL/hal.c ../BSL/_cout.c ../BSL/_xtoa.c ../VM\ Stack/vmstack.c -o _admin.o

avr-objcopy -O ihex -j .text -j .data _admin.o  _admin.hex

avrdude -c arduino -p atmega328p -b 57600 -P $1 -D -Uflash:w:_admin.hex:i