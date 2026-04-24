#include "fart.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

static void put_str(const char *s)
{
    write(1, s, strlen(s));
}
static void put_char(char c)
{
    write(1, &c, 1);
}

static void put_int(int n)
{
    char buf[12];
    int i = 0;

    if (n < 0) { write(1, "-", 1); n = -n; }
    if (n == 0) { write(1, "0", 1); return; }
    while (n > 0) { buf[i++] = '0' + (n % 10); n /= 10; }
    while (i--) write(1, &buf[i], 1);
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