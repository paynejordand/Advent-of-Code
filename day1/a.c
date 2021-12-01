#include <stdio.h>

int main()
{
    int lastNum;
    int currNum;
    int increased = 0;

    char line[5];

    FILE* file = fopen("input.txt", "r");

    fgets(line, 5, file);
    sscanf(line, "%d", &lastNum);

    while(!feof(file))
    {
        fgets(line, 5, file);
        sscanf(line, "%d", &currNum);
        if (currNum > lastNum)
        {
            increased++;
        }
        lastNum = currNum;
    }

    printf("%d\n", increased);

    return 0;
}