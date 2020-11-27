/* _cout.c - Implementation of a Console for Cm Hardware Abstract Layer for Output Interface.
//
// Copyright (C) 1999-2020 by Michel de Champlain
//
*/

#include "_outdesc.h"

#if ConsoleOutputWithPrintf

#include <stdio.h>

static void COut_PutB(bool b)        { printf("%s", b ? "true" : "false"); }
static void COut_PutC(char c)        { printf("%c", c); }
static void COut_PutS(const char* s) { printf("%s", s); }
static void COut_PutI(i32  i)        { printf("%ld", i); }
static void COut_PutU(u32  u)        { printf("%lu", u); }
static void COut_PutX(u32  u)        { printf("%08lX", u); } // To make hex output always aligned to 8 hex digits.
static void COut_PutN(void)          { printf("\n"); }

#else
#include "_xtoa.h"
#include <avr/io.h>

#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

static void uart_print_Char(char c) {
    // Wait until buffer is empty
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = c;
}

// External refs to 'console.c' without
void Console_Putchar(char  c) { uart_print_Char(c); }


static char  buf[12];                /* to cover max size (12) "i32" (10+sign+null) */

static void COut_Init(void) {
    // Set baud rate
    UBRR0H = (MYUBRR >> 8);
    UBRR0L = MYUBRR;

    // Enable receiver and transmitter
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);

    // 8 bit data frame, 1 stop bit
    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);

}

static void COut_PutC(char c)        { Console_Putchar(c); }
static void COut_PutS(const char* s) { while (*s) Console_Putchar(*s++); }
static void COut_PutI(i32  i)        { System_itoa(i, buf); COut_PutS(buf); }
static void COut_PutU(u32  u)        { System_utoa(u, buf, 10); COut_PutS(buf); }
static void COut_PutX(u32  x)        { System_utoa(x, buf, 16); COut_PutS(buf); } // Same behavior as Dos16 VM: 
                                                                                   // Hex alpha in upppercase
static void COut_PutN(void)          { Console_Putchar('\n'); }
static void COut_PutB(bool b)        { COut_PutS(b ? "true" : "false"); }
#endif

static IVMOutDesc cout = {
    COut_PutB,
    COut_PutC,
    COut_PutI,
    COut_PutU,
    COut_PutS,
    COut_PutX,
    COut_PutN
};

static bool init = 0;

IOut Out_GetFactory(const char* whichOne) {
    if (!init) {
        whichOne = 0; // To avoid the warning on the unreferenced formal parameter
        COut_Init();
        init = true;
    }
    return &cout;
}

#ifdef DebugBSL
#include <util/delay.h>
#define MS_DELAY 2000

int main(void) {
    Out_GetFactory("");
    COut_PutS("Test");
    COut_PutN();
    COut_PutI(0x80000000L);
    COut_PutN();
    COut_PutX(0xFFFFFFFFL);
    COut_PutN();
}

#endif