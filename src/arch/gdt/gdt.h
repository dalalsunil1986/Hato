/*
    GDT Header
*/

#pragma once

#include "devices/x86.h"
#include <stddef.h>
#include <stdint.h>

void init_gdt();

struct gdt_pointer
{
    uint16_t limit;
    uint64_t base;
}__attribute__((packed));

struct gdt_descriptor
{
    uint16_t limit_low16;
    uint16_t base_low16;
    uint8_t base_mid8;
    uint16_t flags;
    uint8_t base_high8;
}__attribute__((packed));


