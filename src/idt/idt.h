#pragma once                    // Je sais, c'est pas ouf de l'utiliser :p | I know, it's not ok to use it :p

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

struct IDT_entry
{
    unsigned short int offset_lowerbits;
    unsigned short int selector;
    unsigned char zero;
    unsigned char type_attr;
    unsigned short int offset_higherbits;
};

struct IDT_entry IDT[256];



