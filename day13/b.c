#include <stdio.h>

#define r 893
#define c 1311

void zeroGrid(char grid[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            grid[i][j] = '.';
        }
    }
}

void printGrid(char grid[r][c], int mc, int mr)
{
    for (int i = 0; i < mr; i++)
    {
        for (int j = 0; j < mc; j++)
        {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void fold_row(char grid[r][c], int *mc, int *mr, int line)
{
    int offset = ((*mr) % 2);
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < *mc; j++)
        {
            char overlap = grid[(*mr - offset) - i][j];
            grid[i][j] = (overlap == '#') ? overlap : grid[i][j];
        }
    }
    (*mr) = line + offset;
}

void fold_col(char grid[r][c], int *mc, int *mr, int line)
{
    int offset = ((*mc) % 2);
    for (int i = 0; i < *mr; i++)
    {
        for (int j = 0; j < line; j++)
        {
            char overlap = grid[i][(*mc - offset) - j];
            grid[i][j] = (overlap == '#') ? overlap : grid[i][j];
        }
    }
    (*mc) = line + offset;
}

void fold(char grid[r][c], int *mc, int *mr, char axis, int line)
{
    if (axis == 'y')
        fold_row(grid, mc, mr, line);
    else
        fold_col(grid, mc, mr, line);
}

int main(void)
{
    int col, row;
    char grid[r][c];
    zeroGrid(grid);
    int maxRow = 0;
    int maxCol = 0;

    while (scanf("%d,%d ", &col, &row) == 2)
    {
        maxCol = (col >= maxCol) ? (col  +1) : maxCol;
        maxRow = (row >= maxRow) ? (row + 1) : maxRow;
        grid[row][col] = '#';
    }

    char fold_axis;
    int fold_line;

    while (!feof(stdin))
    {
        scanf("fold along %c=%d ", &fold_axis, &fold_line);
        fold(grid, &maxCol, &maxRow, fold_axis, fold_line);
    }

    int count = 0;
    for (int i = 0; i < maxRow; i++)
    {
        for (int j = 0; j < maxCol; j++)
        {
            if (grid[i][j] == '#')
                count++;
        }
    }

    printGrid(grid, maxCol, maxRow);

    printf("%d\n", count);

    return 0;
}