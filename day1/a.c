#include <stdio.h>

int main()
{
    int lastNum = 99999999;
    int currNum;
    int increased = 0;
    FILE* file = fopen("input.txt", "r");
    
    while(!feof(file))
    {
        fscanf(file, "%d ", &currNum);
        if (currNum > lastNum)
            increased++;
        
        lastNum = currNum;
    }
    printf("%d\n", increased);
    fclose(file);
    return 0;
}