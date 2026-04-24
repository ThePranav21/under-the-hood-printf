#include "fart.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

static void put_str(const char *s)
{
    write(1, s, strlen(s));
}

int fart(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    int i = 0;
    while (fmt[i])
    {
        if (fmt[i] == '%' && fmt[i + 1])
        {
            i++;
            if (fmt[i] == 's')
                put_str(va_arg(args, char *));
        }
        else
            write(1, &fmt[i], 1);
        i++;
    }
    va_end(args);
    return 0;
}