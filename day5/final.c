#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G_SIZE 1000
#define IN_SIZE 500

typedef struct
{
    int x1;
    int y1;
    int x2;
    int y2;
} line_segment;

void initGrid(int grid[G_SIZE][G_SIZE])
{
    for(int i = 0; i < G_SIZE; i++)
    {
        for(int j = 0; j < G_SIZE; j++)
        {
            grid[i][j] = 0;
        }
    }
}

void addHoriz(line_segment line, int grid[G_SIZE][G_SIZE], int* overlaps)
{
    int startX = (line.x1 < line.x2) ? line.x1 : line.x2;
    int endX = (line.x1 > line.x2) ? line.x1 : line.x2;
    int y = line.y1;
    for(int i = startX; i <= endX; i++)
    {
        grid[y][i]++;
        if(grid[y][i] == 2)
            (*overlaps)++;
    }
}

void addVert(line_segment line, int grid[G_SIZE][G_SIZE], int* overlaps)
{
    int startY = (line.y1 < line.y2) ? line.y1 : line.y2;
    int endY = (line.y1 > line.y2) ? line.y1 : line.y2; 
    int x = line.x1;
    for(int i = startY; i <= endY; i++)
    {
        grid[i][x]++;
        if(grid[i][x] == 2)
            (*overlaps)++;
    }
}

void addPosDiag(line_segment line, int grid[G_SIZE][G_SIZE], int* overlaps)
{
    int startX = (line.x1 < line.x2) ? line.x1 : line.x2;
    int endX = (line.x1 > line.x2) ? line.x1 : line.x2;
    int y = (line.y1 < line.y2) ? line.y1 : line.y2;
    for(int i = startX; i <= endX; i++)
    {
        grid[y][i]++;
        if(grid[y++][i] == 2)
            (*overlaps)++;
    }
}

void addNegDiag(line_segment line, int grid[G_SIZE][G_SIZE], int* overlaps)
{
    int startY = (line.y1 > line.y2) ? line.y1 : line.y2;
    int endY = (line.y1 < line.y2) ? line.y1 : line.y2;
    int x = (line.x1 < line.x2) ? line.x1 : line.x2;
    for(int i = startY; i >= endY; i--)
    {
        grid[i][x]++;
        if(grid[i][x++] == 2)
            (*overlaps)++;
    }
}

void checkVents(line_segment line, int grid[G_SIZE][G_SIZE], int* overlap)
{
    if (line.x1 == line.x2)
    {
        addVert(line, grid, overlap);
    }
    else if (line.y1 == line.y2)
    {
        addHoriz(line, grid, overlap);
    }
    else if ((line.x1 - line.x2) == (line.y1 - line.y2))
    {
        addPosDiag(line, grid, overlap);
    }
    else
    {
        addNegDiag(line, grid, overlap);
    }
}

int main(void)
{
    int overlaps;
    line_segment line;

    int grid[G_SIZE][G_SIZE];
    initGrid(grid);

    while(!feof(stdin))
    {
        scanf("%d,%d -> %d,%d ", &(line.x1), &(line.y1), &(line.x2), &(line.y2));
        checkVents(line, grid, &overlaps);
    }

    printf("%d\n", overlaps);

    return 0;
}