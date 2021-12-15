#include <stdio.h>
#include <stdlib.h>

// test: 10x5
// input 100x100
#define width 100
#define height 100

typedef struct
{
    int i;
    int j;
    int size;
} basin;

int basin_cmp(const void *a, const void *b)
{
    const basin *left = (const basin *)a;
    const basin *right = (const basin *)b;

    return (left->size > right->size);
}

int checkBasin(int tubes[height][width], int checked[height][width], int i, int j)
{
    if (i == -1 || j == -1 || i == height || j == width)
        return 0;
    if (checked[i][j] || tubes[i][j] == 9)
        return 0;

    checked[i][j] = 1;
    int up = checkBasin(tubes, checked, i - 1, j);
    int right = checkBasin(tubes, checked, i, j + 1);
    int down = checkBasin(tubes, checked, i + 1, j);
    int left = checkBasin(tubes, checked, i, j - 1);
    return 1 + up + down + left + right;
}

int checkTubes(int tubes[height][width], int checked[height][width])
{
    basin basins[3] =
        {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i != 0)
                if (tubes[i][j] >= tubes[i - 1][j])
                    continue;

            if (i != height - 1)
                if (tubes[i][j] >= tubes[i + 1][j])
                    continue;

            if (j != 0)
                if (tubes[i][j] >= tubes[i][j - 1])
                    continue;

            if (j != width - 1)
                if (tubes[i][j] >= tubes[i][j + 1])
                    continue;

            int size = checkBasin(tubes, checked, i, j);
            if (size > basins[0].size)
            {
                basins[0] = (basin){i, j, size};
                qsort(basins, 3, sizeof(basin), basin_cmp);
            }
        }
    }
    return (basins[0].size * basins[1].size * basins[2].size);
}

int main(void)
{
    int tubes[height][width];
    int checked[height][width];

    for (int i = 0; i < height; i++)
    {
        char c;
        for (int j = 0; j < width; j++)
        {
            scanf("%c", &c);
            tubes[i][j] = c - '0';
            checked[i][j] = 0;
        }
        scanf("%c\n", &c);
    }

    printf("%d\n", checkTubes(tubes, checked));

    return 0;
}
