//
// Created by Morteza Ahmadi on 2020-11-30.
//

#include "../HAL/hal.h"
#include "../HAL/out.h"
#include "../HAL/loader.h"
#include "vm.h"

#define Target      "(ATMega328P)"
#define VMName      "Cm Virtual Machine "
#define AppSuffix   ""
#define AppName     "cm"
#define Version     " v0.1.00.1101a "
#define Copyright   "Copyright (c) 2001-2020  Michel de Champlain"

#define Ack 0xCC
bool loaderStatus;

// Banner = VMname AppSuffix Version Copyright
static void DisplayBanner() {
    VMOut_PutS(VMName); VMOut_PutS(AppSuffix); VMOut_PutS(Version); VMOut_PutS(Target); VMOut_PutN();
    VMOut_PutS(Copyright); VMOut_PutN();
}

// A "small (4-bytes) hardcoded program" which will
// print '1' on the console output (with PuTTY or HyperTerminal set at 9600 baud and 8N1):

#ifdef task4
u8 mem[]= { 0xE1, 0x00, 0x25, 0x71, 0xD5, 0x00, 0x2F, 0xFF, 0x85, 0xD5, 0x00, 0x44, 0xFF, 0x85,
            0xD9, 0x09, 0xA8, 0xE0, 0x0E, 0xA0, 0x90, 0x1C, 0xE3, 0x04, 0xE0, 0x09, 0xA0, 0xB4, 0x00, 0xFF,
            0x82, 0xE0, 0xF4, 0xFF, 0x87, 0x03, 0x04, 0xE7, 0xFF, 0xFF, 0xE7, 0xFF, 0xDB, 0x00, 0x54, 0x2E,
            0x53, 0x74, 0x6D, 0x74, 0x00, 0x54, 0x65, 0x73, 0x74, 0x20, 0x31, 0x31, 0x3A, 0x20, 0x62, 0x72,
            0x65, 0x61, 0x6B, 0x20, 0x53, 0x74, 0x61, 0x74, 0x65, 0x6D, 0x65, 0x6E, 0x74, 0x0A, 0x00, 0x39,
            0x38, 0x37, 0x36, 0x35, 0x34, 0x33, 0x32, 0x31, 0x30, 0x0A, 0x00 };
#else
u8 mem[36];
#endif

int main(int argc, char* argv[]) {
    Hal_Init();
#ifdef task4
    DisplayBanner();
            VM_Init(mem);
            VM_execute(mem);
#else
    while(1) {
        loaderStatus = load(mem);
        if (loaderStatus == Success) {
            DisplayBanner();
            VM_Init(mem);
            VM_execute(mem);

            VMOut_PutC((char) Ack);
            VMOut_PutC((char) 0);

        } else {
            return -1;
        }
    }
#endif
    return 0;
}