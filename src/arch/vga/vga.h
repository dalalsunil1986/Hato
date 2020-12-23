#ifndef _HATO_VGA_H_
#define _HATO_VGA_H_

#pragma once
#include "arch/debug/x86.h"
#include <stdbool.h>
#include <stdarg.h>
#include <stdint.h>

#define VGA_ADDRESS 0xb8000
#define VGA_COLOR(character, color) ((uint16_t)(character) | (uint16_t)(color) << 8)
#define VGA_BLACK 0
#define VGA_BLUE 1
#define VGA_GREEN 2
#define VGA_CYAN 3
#define VGA_RED 4
#define VGA_PURPLE 5
#define VGA_BROWN 6
#define VGA_GRAY 7
#define VGA_DARK_GRAY 8
#define VGA_LIGHT_BLUE 9
#define VGA_LIGH_GREEN 10
#define VGA_LIGHT_CYAN 11
#define VGA_LIGHT_RED 12
#define VGA_LIGHT_PURPLE 13
#define VGA_YELLOW 14
#define VGA_WHITE 15

#define BYTES_FOR_EACH_ELEMENT 2
#define COLUMNS 80
#define LINES 25
#define SIZESCREEN BYTES_FOR_EACH_ELEMENT * COLUMNS * LINES

void VGA_Enable_Cursor(int x, int y);
void VGA_Update_Cursor(uint8_t cursor_start, uint8_t cursor_end);

void hprint(const char* str, int color);
void hprint_newline(void);
void clear(void);

#endif
