#include <stdio.h>
#include <stdlib.h>

int foo(void)
{
    char a = -6;
    unsigned char b = 6;
    printf("signed shift  : %d, %d\n", a >> 1, a >> 2);
    printf("signed div    : %d, %d\n", a / 2, a / 4);
    printf("unsigned shift: %d, %d\n", b >> 1, b >> 2);

    return 0;
}

int main()
{
    foo();
    return 0;
}
