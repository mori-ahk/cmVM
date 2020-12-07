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

static u8 mem[36];

int main(int argc, char* argv[]) {
    Hal_Init();
    loader_init();
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

    return 0;
}