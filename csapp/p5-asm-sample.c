#include <stdio.h>
#include <stdlib.h>

void swap(size_t *xp, size_t *yp)
{
    size_t t0 = *xp;
    size_t t1 = *yp;
    *xp = t1;
    *yp = t0;
}

void swap_1(size_t *xp, size_t *yp)
{
    *xp = *xp ^ *yp;
    *yp = *xp ^ *yp;
    *xp = *xp ^ *yp;
}

#ifndef NMIPS
int main(void)
{
    size_t a = 0xabcd1234;
    size_t b = 0x33cc77dd;
    printf("a = %.8zx, b = %.8zx\n", a, b);
    swap(&a, &b);
    printf("a = %.8zx, b = %.8zx\n", a, b);
    swap_1(&a, &b);
    printf("a = %.8zx, b = %.8zx\n", a, b);
    swap(&a, &b);
    printf("a = %.8zx, b = %.8zx\n", a, b);

    return 0;
}
#endif
