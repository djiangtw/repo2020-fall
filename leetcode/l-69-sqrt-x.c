#include <stdio.h>
#include <stdlib.h>

/* next: #367 valid perfect square */
#define NUM 15

int mySqrt(int x)
{
    int r;
    r = x;
    if( r == 0 )
        return 0;

    if( r == 1)
        return 1;

    if(x >= 46340*46340)
        return 46340;

    for(r = 0; r < x; r++)
    {
        if (x < r*r)
        {
            break;
        }
    }

    return r - 1;
}

int main(int argc, char** argv)
{
    int n = NUM;
    if(argc == 2)
        n = atoi(argv[1]);

    printf("sqrt(%d) : %d\n", n, mySqrt(n));

    return 0;
}
