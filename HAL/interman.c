/* interman.c -- Interrupt Management Interface for Dos16 - Small Model (with Digital Mars C/C++)
//
// Copyright (C) 1985-2019 by Michel de Champlain
//
*/

#ifdef onTarget
#include "../BSL/_interman.h"
#include "interman.h"
#include <avr/io.h>
#include <avr/interrupt.h>

//s#define SREG 0x3F

//#define sei()  __asm__ __volatile__ ("sei" ::: "memory")
//#include <dos.h>

//typedef void (__interrupt __far *Handler)();

//#define __cli()  __emit__(0xFA)
//#define __sli()  __emit__(0xFB)

//#if ____x8086
// End-of-interrupt to 8259 controller
// B0 20    mov  al, 0x20
// E6 20    out  0x20, als
//#define __endOfInterrupt() (__emit__(0xB0),__emit__(0x20),__emit__(0xE6),__emit__(0x20))
//#define __iret()            __emit__(0xCF)
//#endif

//#define __restore()        (__emit__(0x55),__emit__(0x89),__emit__(0xE5),__emit__(0xFF),__emit__(0x76),__emit__(0x04),__emit__(0x9D),__emit__(0x5D))
u32 vector_table[7];

void  Interrupt_Disable(void) { SREG = (0 << 7); } // Disabling the global interupt register 
void  Interrupt_Enable(void)  { SREG = (1 << 7); } // Enabling the global interupt register  

u16 GetStatusReg(void) { 
	return SREG; // Returns the status of the register
}

u16   Interrupt_SaveAndDisable(void) { 
    u16 saveStatus = SREG; // Saving the status of the interupt register
    cli();                 // Disabling the interupts
    return saveStatus;     // Returning the status of the global interupt register
}

void  Interrupt_Restore(u16 flags) { 
    SREG = flags; // Restoring the register
}

 void  Interrupt_SetVector(u8 number, u32 handlerAddr) {
    vector_table[(int) number] = handlerAddr; // vector address gets called for specific vector needed by the system
}

 u32   Interrupt_GetVector(u8 number) {
    return vector_table[(int) number]; // Returning the vector address of specified number
}

#endif