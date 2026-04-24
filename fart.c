#include "fart.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

static void put_char(char c)    { write(1, &c, 1); }
static void put_str(const char *s) { write(1, s, strlen(s)); }

static void put_int(int n)
{
    char buf[12];
    int i = 0;
    if (n < 0) { write(1, "-", 1); n = -n; }
    if (n == 0) { write(1, "0", 1); return; }
    while (n > 0) { buf[i++] = '0' + (n % 10); n /= 10; }
    while (i--) write(1, &buf[i], 1);
}

static void put_hex(unsigned int n)
{
    char *digits = "0123456789abcdef";
    char buf[8];
    int i = 0;
    if (n == 0) { write(1, "0", 1); return; }
    while (n > 0) { buf[i++] = digits[n % 16]; n /= 16; }
    while (i--) write(1, &buf[i], 1);
}

typedef struct {
    char    spec;
    void    (*fn)(va_list *);
} t_handler;

static void handle_s(va_list *args) { put_str(va_arg(*args, char *)); }
static void handle_c(va_list *args) { put_char(va_arg(*args, int)); }
static void handle_d(va_list *args) { put_int(va_arg(*args, int)); }
static void handle_x(va_list *args) { put_hex(va_arg(*args, unsigned int)); }
static void handle_pct(va_list *args) { (void)args; put_char('%'); }

static t_handler handlers[] = {
    {'s', handle_s},
    {'c', handle_c},
    {'d', handle_d},
    {'x', handle_x},
    {'%', handle_pct},
    {0, NULL}
};

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
            int j = 0;
            while (handlers[j].spec)
            {
                if (handlers[j].spec == fmt[i])
                    { handlers[j].fn(&args); break; }
                j++;
            }
        }
        else
            write(1, &fmt[i], 1);
        i++;
    }
    va_end(args);
    return 0;
}