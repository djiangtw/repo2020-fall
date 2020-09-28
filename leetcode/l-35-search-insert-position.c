#include <stdio.h>
#include <stdlib.h>

int ar1[] = {2, 4, 5};
int ar2[] = {1, 3, 3, 5, 6, 7, 9, 10};
int ar3[] = {1, 3, 5, 6};
int ar4[] = {};

int searchInsert(int* nums, int numsSize, int target)
{
    int r = 0;

    if(numsSize == 0)
        return 0;

    while(r < numsSize)
    {
        if(nums[r] >= target)
        {
            break;
        }
        r++;
    }

	return r;
}

void init(void)
{
}


int main(void)
{
    int r;
    r = searchInsert(ar4, 0, 0);
    printf("result: %d\n", r);
    return 0;
}
