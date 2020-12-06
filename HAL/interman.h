/* interman.h -- Interrupt Management Interface
//
// Copyright (C) 1985-2019 by Michel de Champlain
//
*/

#ifndef hal_interman_h
#define hal_interman_h

#include "../BSL/_stdtype.h"
#include "../BSL/_interman.h"

// End-of-interrupt to 8259 controller
// B0 20    mov  al, 0x20
// E6 20    out  0x20, al
//#define __endOfInterrupt() (__emit__(0xB0),__emit__(0x20),__emit__(0xE6),__emit__(0x20))
//#define __iret()            __emit__(0xCF)
 u16 GetStatusReg(void);
 void  Interrupt_Disable(void);
 void  Interrupt_Enable(void);
 u16   Interrupt_SaveAndDisable(void);
 void  Interrupt_Restore(u16 flags);
 void  Interrupt_SetVector(u8 number, u32 handlerAddr);
 u32   Interrupt_GetVector(u8 number);

#endif
