//
// Created by Morteza Ahmadi on 2020-12-06.
//

#ifdef onTarget
#include "loader.h"
#include "../BSL/_uart.h"
#include <avr/io.h>
#include <avr/interrupt.h>

static bool load(u8* mem) {
	while (counter < 11) {
		char input = uart_RxChar();

		// Check if non-zero and currently reading packet
		if (input != 0x00 && isProcessing == false) {
			isProcessing = true;
			mem[counter++] = input;
		}
		else if (input == 0x00 && isProcessing == true) {
			isProcessing = false;
			counter = 0;
			return Success;
		}
	}

	// if bigger than 11 bytes, invalid command.
	return InvalidCmd;
}

void loader_init(void) {
    UCSR0B |= (1 << RXEN0) | (1 << RXCIE0); // Enable Receiver bit and Stop flag bit
    sei();
}

#endif