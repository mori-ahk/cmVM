/* interman.h -- Interrupt Management Interface
//
// Copyright (C) 1985-2019 by Michel de Champlain
//
*/

#ifndef bsl_interman_h
#define bsl_interman_h

#include "_stdtype.h"
#include <stddef.h>

// End-of-interrupt to 8259 controller
// B0 20    mov  al, 0x20
// E6 20    out  0x20, al
//#define __endOfInterrupt() (__emit__(0xB0),__emit__(0x20),__emit__(0xE6),__emit__(0x20))
//#define __iret()            __emit__(0xCF)

//u32 vector_table[7] = { 0x0000, 0x002, 0x0004, 0x0006, 0x0008, 0x000A, 0x000C } //array vector addresses of atmega328p first 7 adresses

#endif
