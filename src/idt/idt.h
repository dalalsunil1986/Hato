#pragma once

#include <stdint.h>

void idt_initializating(void);

struct IDTDescription
{
    uint16_t offset_1;
    uint16_t selector;
    uint8_t ist;
    uint8_t type_attr;
    uint16_t offset_2;
    uint32_t offset_3;
    uint32_t zero;
};


