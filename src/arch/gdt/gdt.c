#include "arch/gdt/gdt.h"
#include "arch/debug/printf.h"

#include <stdint.h>

struct gdt_descriptor gdt[8];
struct gdt_pointer gdtr = { .limit = sizeof(struct gdt_descriptor) - 1, .base = (uint64_t)gdt };

void hatoGlobalDescriptorTable_load()
{
    asm volatile("lgdt %0"
                 :
                 : "m"(gdtr)
                 :
                 : "memory");

    asm volatile(R"(
        mov %%rsp, %%rax
        push $0x10
        push %%rax
        pushf
        push $0x08
        push $1f
        iretq
        1:
        mov $0x10, %%ax
        mov %%ax, %%ds
        mov %%ax, %%es
        mov %%ax, %%ss
        mov %%ax, %%fs
        mov %%ax, %%gs
    )"
                 :
                 :
                 : "rax", "memory");
    
    
    
    printf("GDT initialized. \n");
}

void hatoGlobalDescriptorTable_init()
{
    gdt[1] = (struct gdt_descriptor) { .access = 0b10011010, .granularity = 0b00100000 };
    gdt[2] = (struct gdt_descriptor) { .access = 0b10010010, .granularity = 0 };

    hatoGlobalDescriptorTable_load();
}
