#include <stdio.h>
#include <string.h>

// test: 10x5
//input 110x100
int main(void)
{
    int len = 111; //test:10 input:110
    char val[1000];
    while(!feof(stdin))
    {
        
        scanf("%s", val);
    }

    printf("%d\n", (int)strlen(val));
    return 0;
}