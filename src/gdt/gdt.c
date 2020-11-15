#include "gdt.h"
#include "arch/com.h"
#include "printf.h"

void gdt_initializating(void)
{
    GDT[0] = {.base=0, .limit=0, .type=0};
    GDT[1] = {.base=0, .limit=0xffffffff, .type=0x9A};
    GDT[2] = {.base=0, .limit=0xffffffff, .type=0x92};
    GDT[3] = {.base=&myTss, .limit=sizeof(myTss), .type=0x89};
}

void encodeGdtEntry(uint8_t *target, struct GDT source)
{

    gdt_initializating();

    if ((source.limit > 65536) && ((source.limit & 0xFFF) != 0xFFF))
    {
        printf("You can't do that! \n");
    }

    if (source.limit > 65536)
    {
        source.limit = source.limit >> 12;
        target[6] = 0xC0;
    } else {
        target[6] = 0x40;
    }

    target[0] = soure.limit & 0xFF;
    target[1] = (source.limit >> 8) & 0xFF;
    target[6] = (source.limit >> 16) & 0xFF;

    target[2] = source.base & 0xFF;
    target[3] = (source.base >> 8) & 0xFF;
    target[4] = (source.base >> 16) & 0xFF;
    target[7] = (source.base >> 24) & 0xFF;

    target[5] = source.type;
}

