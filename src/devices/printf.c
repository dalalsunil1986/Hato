#include "devices/printf.h"
#include "devices/com.h"
#include <stddef.h>

void printf(const char* msg)
{
    for (size_t i = 0; msg[i]; i++)
    {
        write_serial(msg[i]);
    }
}

