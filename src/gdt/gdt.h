/*
========================================================================================
En vrai elle est pas complète et utilse #pragma once qui askip est totalement useless.
Mais bon considérons que je suis débutant et que je peux améliorer ce code plus tard.
En attendant cette gdt n'est pas forcément fonctionelle à 100%
========================================================================================
*/

#pragma once
#include <stdint.h>

void gdt_initializating(void);

struct gdt_pointer
{
    uint16_t limit;
    uint64_t base;
} __attribute__((packed));

struct gdt_descriptor
{
    uint16_t limit_low16;
    uint16_t base_low16;
    uint8_t base_mid8;
    uint16_t flags;
    uint8_t base_high8;
} __attribute__((packed));


