#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// test: 10x5
// input 100x100
#define width 100
#define height 100

int upLess(int tubes[height][width], int i, int j)
{
    return (tubes[i][j] >= tubes[i+1][j]);
}

int downLess(int tubes[height][width], int i, int j)
{
    return (tubes[i][j] >= tubes[i-1][j]);
}

int leftLess(int tubes[height][width], int i, int j)
{
    return (tubes[i][j] >= tubes[i][j-1]);
}

int rightLess(int tubes[height][width], int i, int j)
{
    return (tubes[i][j] >= tubes[i][j+1]);
}

int checkTubes(int tubes[height][width])
{
    int sum = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i != 0)
                if (downLess(tubes, i, j))
                    continue;
            
            if (i != height - 1)
                if (upLess(tubes, i, j))
                    continue;
            
            if (j != 0)
                if (leftLess(tubes, i, j))
                    continue;

            if (j != width - 1)
                if (rightLess(tubes, i, j))
                    continue;

            sum += (tubes[i][j] + 1);
        }
    }
    return sum;
}

int main(void)
{
    int tubes[height][width];

    for (int i = 0; i < height; i++)
    {
        char c;
        for (int j = 0; j < width; j++)
        {
            scanf("%c", &c);
            tubes[i][j] = c - '0';
        }
        scanf("%c\n", &c);
    }

    printf("%d\n", checkTubes(tubes));

    return 0;
}
