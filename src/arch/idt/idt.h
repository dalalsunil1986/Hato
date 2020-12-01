/**

#pragma once

#include "arch/debug/x86.h"
#include <stdint.h>
#include <stddef.h>

struct IDT_entry
{
    uint16_t offset_1;
    uint16_t selector;

};

**/