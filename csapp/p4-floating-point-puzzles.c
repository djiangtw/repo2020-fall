#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int foo(void)
{
    int x = 99999999;
    float f = 1.33124321432;
    double d = 1.33124321432;
    double d1 = -123843211.43124321;
    
    printf("x == (int)(float) x ? %s\n", (x == (int)(float) x) ? "true" : "false");
    printf("x == (int)(double) x ? %s\n", (x == (int)(double) x) ? "true" : "false");
    printf("f == (float)(double) f ? %s\n", (f == (float)(double) f) ? "true" : "false");
    printf("d == (double)(float) d ? %s\n", (d == (double)(float) d) ? "true" : "false");
    printf("f == -f ? %s\n", (f == -f) ? "true" : "false");
    printf("2/3 == 2/3.0 ? %s\n", (2/3 == 2/3.0) ? "true" : "false");
    printf("d1 < 0 => ((d1*2) < 0.0) ? %s\n", ((d1*2) < 0.0) ? "true" : "false");
    printf("(d + f) - d == f ? %s\n", ((d + f) - d == f) ? "true" : "false");

    return 0;
}

int main(void)
{
    foo();
    return 0;
}
