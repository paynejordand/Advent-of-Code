#include <stdio.h>

#define r 895  // test: 15 input: 895
#define c 1311 // test: 11 input: 1311

void zeroGrid(int grid[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            grid[i][j] = 0;
        }
    }
}

void printGrid(int grid[r][c], int mc, int mr)
{
    for (int i = 0; i < mr; i++)
    {
        for (int j = 0; j < mc; j++)
        {
            if (grid[i][j])
                printf("#");
            else
                printf(".");
        }
        printf("\n");
    }
    printf("\n");
}

void fold_row(int grid[r][c], int *mc, int *mr, int line)
{
    for (int row = 0; row <= line; row++)
    {
        for (int col = 0; col < *mc; col++)
        {
            grid[line - row][col] += grid[line + row][col];
        }
    }
    *mr = line;
}

void fold_col(int grid[r][c], int *mc, int *mr, int line)
{
    for (int row = 0; row < *mr; row++)
    {
        for (int col = 0; col <= line; col++)
        {
            grid[row][line - col] += grid[row][line + col];
        }
    }
    *mc = line;
}

void fold(int grid[r][c], int *mc, int *mr, char axis, int line)
{
    if (axis == 'y')
        fold_row(grid, mc, mr, line);
    else
        fold_col(grid, mc, mr, line);
}

int main(void)
{
    int col, row;
    int grid[r][c];
    zeroGrid(grid);
    int maxRow = r;
    int maxCol = c;
    int fold_line;
    char fold_axis;

    while (!feof(stdin))
    {
        while (scanf("%d,%d ", &col, &row) == 2)
        {
            grid[row][col] = 1;
        }
        scanf("fold along %c=%d ", &fold_axis, &fold_line);
        fold(grid, &maxCol, &maxRow, fold_axis, fold_line);
    }

    int count = 0;
    for (int i = 0; i < maxRow; i++)
    {
        for (int j = 0; j < maxCol; j++)
        {
            if (grid[i][j])
                count++;
        }
    }

    printGrid(grid, maxCol, maxRow);

    printf("%d\n", count);

    return 0;
}