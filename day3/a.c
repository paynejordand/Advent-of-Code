#include <stdio.h>
#include <math.h>

int main(void)
{
    int bitCount[2][12] = {0};
    int gammaRate = 0;
    int epsilonRate = 0;

    char line[12];

    while(!feof(stdin))
    {
        scanf("%s ", line);

        for(int i = 0; i < 12; i++)
            bitCount[line[i]-'0'][i] += 1;
    }

    for(int i = 0; i < 12; i++)
    {
        gammaRate += ((pow(2, 12-i-1)) * (bitCount[1][i] > bitCount[0][i]));
        epsilonRate += ((pow(2, 12-i-1)) * (bitCount[1][i] < bitCount[0][i]));
    }
    printf("%d\n", gammaRate * epsilonRate);

    return 0;
}