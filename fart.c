#include "fart.h"
#include <unistd.h>
#include <string.h>

int fart(const char *fmt, ...)
{
    int len = strlen(fmt);
    write(1, fmt, len);
    return len;
}