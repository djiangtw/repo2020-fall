#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>



int foo(void)
{
    return INT32_MIN + 9999;
}

int bar(void)
{
    return 0;
}

int main(void)
{
    int x = foo();
    int y = bar();
    unsigned ux = x;
    unsigned uy = y;

    printf("x < 0, (x << 1) = %d, (x*2) = %d, (x + x) = %d\n", x << 1, x * 2, x + x);
    printf("x = %.8x, (x | -x) = %.8x, ((x | -x) >> 31) = %.8x(%d)\n", x, x | -x, (x | -x) >> 31, (x | -x) >> 31);
    return 0;
}
