#include <stdio.h>
#include <string.h>

// test: 11x6
//input 111x101
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
