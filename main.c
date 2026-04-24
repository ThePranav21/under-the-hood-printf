#include "fart.h"
#include <stdio.h>

int main(void)
{
    int f_ret = fart("hello %s, number %d, hex %x\n", "world", 42, 255);
    int p_ret = printf("hello %s, number %d, hex %x\n", "world", 42, 255);
    fart("fart returned: %d\n", f_ret);
    fart("printf returned: %d\n", p_ret);
    return 0;
}