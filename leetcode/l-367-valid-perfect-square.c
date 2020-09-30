#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* next: #367 valid perfect square */
#define NUM (15)
#define MAX_INTSQRT (46340)

bool isPerfectSquare(int num)
{
    int s = MAX_INTSQRT;
    int t;
    if (num > s * s)
        return false;

    t = s;
    while(s > 0)
    {
        if(num < s * s)
        {
            t = s;
            s = s >> 1;
        }
        else
            break;
    }
    for(; s <= t; s++)
    {
        if(num == s*s)
        {
            return true;
        }
        else if(num < s*s) 
        {
            return false;
        }
    }
    return false;
}

int main(int argc, char** argv)
{
    int i = 30;
    int n = NUM;

    while(i--)
    {
        printf("sqrt(%d) : %d\n", i, isPerfectSquare(i));
    };

    return 0;
}
