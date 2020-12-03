//
// Created by Morteza Ahmadi on 2020-11-30.
//

#include "../HAL/hal.h"
#include "../HAL/out.h"
#include "vm.h"

#define Target      "(ATMega328P)"
#define VMName      "Cm Virtual Machine "
#define AppSuffix   ""
#define AppName     "cm"
#define Version     " v0.1.00.1101a "
#define Copyright   "Copyright (c) 2001-2020  Michel de Champlain"

// Banner = VMname AppSuffix Version Copyright
static void DisplayBanner() {
    VMOut_PutS(VMName); VMOut_PutS(AppSuffix); VMOut_PutS(Version); VMOut_PutS(Target); VMOut_PutN();
    VMOut_PutS(Copyright); VMOut_PutN();
}

// A "small (4-bytes) hardcoded program" which will
// print '1' on the console output (with PuTTY or HyperTerminal set at 9600 baud and 8N1):
u8 mem[] = { 0x91, 0xFF, 0x82, 0x00 };

int main(int argc, char* argv[]) {
    Hal_Init();
    DisplayBanner();

    VM_Init(mem);
    VM_execute(mem);
    return 0;
}