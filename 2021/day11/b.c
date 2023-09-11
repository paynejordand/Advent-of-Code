#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void flash(int o[10][10], int f[10][10], int i, int j, int *fl)
{
    // check bounds
    if (i == -1 || j == -1 || i == 10 || j == 10)
        return;

    // check if flashed
    if (f[i][j])
        return;

    // increase and exit if no new flash
    o[i][j]++;
    if (o[i][j] <= 9)
        return;

    (*fl)++;
    f[i][j] = 1;
    o[i][j] = 0;

    for (int x = -1; x <= 1; x++)
        for (int y = -1; y <= 1; y++)
            flash(o, f, i + x, j + y, fl);
}

void resetFlash(int f[10][10])
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            f[i][j] = 0;
}

void printOct(int a[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int oct[10][10];
    int flashed[10][10];
    resetFlash(flashed);

    for (int i = 0; i < 10; i++)
    {
        char c;
        for (int j = 0; j < 10; j++)
        {
            scanf("%c", &c);
            oct[i][j] = c - '0';
        }
        scanf("%c\n", &c);
    }

    int flashes = 0;
    int runs = 0;

    while (flashes != 100)
    {
        flashes = 0;
        runs++;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                flash(oct, flashed, i, j, &flashes);
            }
        }
        resetFlash(flashed);
    }

    printf("%d\n", runs);
    return 0;
}