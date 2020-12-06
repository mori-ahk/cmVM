#ifdef onTarget
#include "_IOReg.h"
#include <avr/io.h>

u32 bsl_IOReg_Read (u32 ioreg) {
	volatile uint8_t* ptr = (uint8_t) ioreg; // ptr pointing to memory address called ioreg
	return (u32) *ptr;                       // Deferencing ptr 
}

void bsl_IOReg_Write(u32 ioreg, u32 value) { 
	volatile uint8_t* ptr = (uint8_t)ioreg; // ptr pointing to memory address called ioreg
	*ptr = value;                           // Changing the value of deferenced ptr to the value 
}

#endif