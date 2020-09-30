#include <stdio.h>
#include <stdlib.h>

int ar1[] = {2, 4, 5};
int ar2[] = {1, 3, 3, -5, 6, 7, -9, 10};
int ar3[] = {1, 3, 5, 6};
int ar4[] = {};

int maxSubArray(int* nums, int numsSize)
{
    int i, j;
    int r = nums[0];

    for(i = 0; i < numsSize; i++)
    {
        int s = 0;
        for(j = i; j < numsSize; j++)
        {
            s += nums[j];
            if(s > r)
                r = s;
        }
    }
    return r;
}

int main(void)
{
    int r;
    r = maxSubArray(ar3, 8);
    printf("result: %d\n", r);
    return 0;
}

