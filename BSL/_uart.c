//
// Created by Morteza Ahmadi on 2020-12-06.
//

#ifdef onTarget
#include "_uart.h"
#include <avr/io.h>

#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

void uart_init(void) {
    // Set baud rate
    UBRR0H = (MYUBRR >> 8);
    UBRR0L = MYUBRR;

    // Enable receiver and transmitter
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);

    // 8 bit data frame, 1 stop bit
    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
}

void uart_TxChar(char c) {
    // Wait until buffer is empty
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = c;
}

char uart_RxChar(void) {
    // Wait until data is received
    while (!(UCSR0A & (1 << RXC0)));

    // Read the data from the RX buffer
    char input = UDR0;
    return input;
}
#endif
