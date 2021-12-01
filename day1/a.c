#include <stdio.h>

int main()
{
    int lastNum;
    int currNum;
    int increased = 0;

    FILE* file = fopen("input.txt", "r");

    fscanf(file, "%d ", &lastNum);

    while(!feof(file))
    {
        fscanf(file, "%d ", &currNum);
        if (currNum > lastNum)
        {
            increased++;
        }
        lastNum = currNum;
    }

    printf("%d\n", increased);

    return 0;
}