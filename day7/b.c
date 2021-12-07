#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int pos[1000];
    int count = 0;    // input:1000 test:10
    int max = 1937;      // input:1937 //test:16
    int min = 0;
    while(!feof(stdin))
    {   
        scanf("%d,", &pos[count++]);
    }


    int minCost = 1410065407;
    for(int i = min; i <= max; i++)
    {
        int cost = 0;
        for(int j = 0; j < count; j++)
        {
            int steps = (abs(pos[j] - i));
            for(int j = 1; j <= steps; j++)
                cost += j;
        }
        minCost = cost < minCost ? cost : minCost;
    }

    printf("%d\n", minCost);

    return 0;
}