#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare (const void  * a, const void * b)
{
    return (*(const char *) a - *(const char *) b);
}

int main(void)
{
    int test[4] = {3, 4, 1, 6};
    char t[4] = "test";

    char fin[1][4];
    strcpy(fin[0], "tes");

    qsort(fin[0], strlen(fin[0]), sizeof(char), compare);

    for(int i = 0; i < strlen(t); i++)
    {
        printf("%c ", fin[0][i]);
    }

    return 0;
}