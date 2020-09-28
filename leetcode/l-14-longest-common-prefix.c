#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SZ_STRS 3
char test[SZ_STRS][20] = {
    "b", 
    "cac", 
    "cag"
};

char** ss;
char * longestCommonPrefix(char ** strs, int strsSize)
{
    char* r;
    int i, j;
    int shortest_len = -1;
    int strs_count = strsSize;

    /* return if no strings */
    if(strs_count == 0)
    {
        r = (char*)malloc(sizeof(char));
        r[0] = 0;
        return r;
    }
    if(strs_count == 1)
    {
        return strs[0];
    }

    strs_count--;
    shortest_len = (int)strlen(strs[strs_count]);
    while(strs_count > 0)
    {
        strs_count--;
        i = (int)strlen(strs[strs_count]);
        if( i < shortest_len)
            shortest_len = i;
    }
    strs_count = strsSize;

    /* return if there's any empty string */
    if(shortest_len == 0)
    {
        strs[0][0] = 0;
        return strs[0];
    }

    /* comparing */
    for(i = 0; i < shortest_len; i++)
    {
        for( j = 0; j < strsSize; j++)
        {
            if(strs[j][i] != strs[0][i])
            {
                strs[0][i] = 0;
                return strs[0];
            }
        }
    }
    strs[0][shortest_len] = 0;
	return strs[0];
}

void init(void)
{
    int i = SZ_STRS;
    ss = (char**)malloc(sizeof(char*) * SZ_STRS);
    while(i != 0)
    {
        i--;
        ss[i] = test[i];
        printf("%s\n", ss[i]);
    }


}

void end(void)
{
    free(ss);
}

int main(void)
{
	int i = 3;
    char* r;

	while(i != 0)
    {
        i--;
        printf("%s, (%d)\n", test[i], (unsigned int)strlen(test[i]));
    }
    init();
    r = longestCommonPrefix(ss, SZ_STRS);

    printf("%s, (%d)\n", r, (unsigned int)strlen(r));
    return 0;
}
