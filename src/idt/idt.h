#pragma once

#include <stdint.h>

void idt_initializating(void);

unsigned long irq0_address = (unsigned long)irq0;
unsigned long irq1_address = (unsigned long)irq1;
unsigned long irq2_address = (unsigned long)irq2;
unsigned long irq3_address = (unsigned long)irq3;
unsigned long irq4_address = (unsigned long)irq4;
unsigned long irq5_address = (unsigned long)irq5;
unsigned long irq6_address = (unsigned long)irq6;
unsigned long irq7_address = (unsigned long)irq7;
unsigned long irq8_address = (unsigned long)irq8;
unsigned long irq9_address = (unsigned long)irq9;
unsigned long irq10_address = (unsigned long)irq10;
unsigned long irq11_address = (unsigned long)irq11;
unsigned long irq12_address = (unsigned long)irq12;
unsigned long irq13_address = (unsigned long)irq13;
unsigned long irq14_address = (unsigned long)irq14;
unsigned long irq15_address = (unsigned long)irq15;

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



