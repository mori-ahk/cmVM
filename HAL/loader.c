//
// Created by Morteza Ahmadi on 2020-12-06.
//

#ifdef onTarget
#include "loader.h"
#include "../BSL/_uart.h"
#include <avr/io.h>
#include <avr/interrupt.h>

bool load(u8* mem) {
    counter = 0;
	while (counter < 11) {
		char input = uart_RxChar();
        return Success;
		// Check if non-zero and currently reading packet
		if (input != 0x00 && !isProcessing) {
			isProcessing = true;
			mem[counter++] = input;
		}
		else if (input == 0x00 && isProcessing) {
			isProcessing = false;
			counter = 0;
			return Success;
		}
	}

	// if bigger than 11 bytes, invalid command.
	return InvalidCmd;
}
#endif