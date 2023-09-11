#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main(void)
{
    uint64_t count = 300;
    uint64_t fish[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    uint64_t newFish[9] = {0, 0, 0, 0, 0, 0, 0, 0 ,0};



    while(!feof(stdin))
    {
        int timer;
        scanf("%d,", &timer);
        fish[timer]++;
    }

    for(int day = 1; day <= 256; day++)
    {
        for(int i = 0; i <=8; i++)
        {
            newFish[i] = fish[(i+1)%9];
        }
        newFish[6] += fish[0];
        count += newFish[8];
        for(int i = 0; i <= 8; i++)
        {
            fish[i] = newFish[i];
        }
    }

    printf("%ld\n", count);
    return 0;
}