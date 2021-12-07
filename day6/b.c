#include <stdio.h>

int main(void)
{
    unsigned long long int count = 300;
    unsigned long long int fish[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    unsigned long long int newFish[9] = {0, 0, 0, 0, 0, 0, 0, 0 ,0};


    int i = 0;
    while(!feof(stdin))
    {
        int timer;
        scanf("%d,", &timer);
        fish[timer]++;
    }

    for(i = 1; i <= 256; i++)
    {
        printf("After %4d days: ", i);
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
        printf("\n");
    }

    printf("%lld\n", count);
    return 0;
}