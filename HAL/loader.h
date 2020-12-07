//
// Created by Morteza Ahmadi on 2020-12-06.
//

#ifndef SRC_LOADER_H
#define SRC_LOADER_H
#include "../BSL/_stdtype.h"

u8 counter;
bool isProcessing;
enum Status { Success = 0x40, InvalidCmd };

bool load(u8* mem);
#endif

