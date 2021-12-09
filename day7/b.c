#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int pos[1000];
    int count = 0;
    int max = 0;
    while(!feof(stdin))
    {   
        scanf("%d,", &pos[count]);
        max = pos[count] > max ? pos[count] : max;
        count++;
    }

    int minCost = 1410065407;
    for(int i = 0; i <= max; i++)
    {
        int cost = 0;
        for(int j = 0; j < count; j++)
        {
            int steps = (abs(pos[j] - i));
            cost += (steps*(steps+1)/2);
        }
        minCost = cost < minCost ? cost : minCost;
    }

    printf("%d\n", minCost);

    return 0;
}