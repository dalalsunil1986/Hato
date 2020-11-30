#include "arch/gdt/gdt.h"
#include "arch/debug/printf.h"

#include <stdint.h>

struct gdt_descriptor gdt[8];
struct gdt_pointer gdtr = { .limit = sizeof(struct gdt_descriptor) - 1, .base = (uint64_t)gdt };

void hatoGlobalDescriptorTable_load()
{
    extern void hatogdtload();
        
    printf("GDT initialized. \n");
}

void hatoGlobalDescriptorTable_init()
{
    gdt[1] = (struct gdt_descriptor) { .access = 0b10011010, .granularity = 0b00100000 };
    gdt[2] = (struct gdt_descriptor) { .access = 0b10010010, .granularity = 0 };

    hatoGlobalDescriptorTable_load();
}
