#include "vga.h"
#include "arch/debug/x86.h"
#include <stdint.h>

unsigned int current_loc = 0;
char* vidptr = (char*)0xb8000;

void hprint(const char* str, int color)
{
    int i = 0;
    while(str[i] != '\0')
    {
        vidptr[current_loc++] = str[i++];
        vidptr[current_loc++] = color;
    }
}

void hprint_newline(void)
{
    unsigned int line_size = BYTES_FOR_EACH_ELEMENT * COLUMNS;
    current_loc = current_loc + (line_size - current_loc % (line_size));
}

void clear(void)
{
    unsigned int i = 0;
    while(i < SIZESCREEN)
    {
        vidptr[i++] = ' ';
        vidptr[i++] = 0x07;
    }
}

