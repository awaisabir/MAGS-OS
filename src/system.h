#ifndef SYSTEM_H
#define SYSTEM_H
#include "kerneltypes.h"

uint8_t inportb(uint16_t _port);

void outport(uint16_t _port,uint8_t data);

#endif
