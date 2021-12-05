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

void readLines(line_segment* lines)
{
    while(!feof(stdin))
    {
        scanf("%d,%d -> %d,%d ", &(lines->x1), &(lines->y1), &(lines->x2), &(lines->y2));
        lines++;
    }
}

void addHoriz(line_segment line, int grid[G_SIZE][G_SIZE])
{
    int startX = (line.x1 < line.x2) ? line.x1 : line.x2;
    int endX = (line.x1 > line.x2) ? line.x1 : line.x2;
    int y = line.y1;
    for(int i = startX; i <= endX; i++)
    {
        grid[y][i]++;
    }
}

void addVert(line_segment line, int grid[G_SIZE][G_SIZE])
{
    int startY = (line.y1 < line.y2) ? line.y1 : line.y2;
    int endY = (line.y1 > line.y2) ? line.y1 : line.y2; 
    int x = line.x1;
    for(int i = startY; i <= endY; i++)
    {
        grid[i][x]++;
    }
}

void addPosDiag(line_segment line, int grid[G_SIZE][G_SIZE])
{
    int startX = (line.x1 < line.x2) ? line.x1 : line.x2;
    int endX = (line.x1 > line.x2) ? line.x1 : line.x2;
    int y = (line.y1 < line.y2) ? line.y1 : line.y2;
    for(int i = startX; i <= endX; i++)
    {
        grid[y++][i]++;
    }
}

void addNegDiag(line_segment line, int grid[G_SIZE][G_SIZE])
{
    int startY = (line.y1 > line.y2) ? line.y1 : line.y2;
    int endY = (line.y1 < line.y2) ? line.y1 : line.y2;
    int x = (line.x1 < line.x2) ? line.x1 : line.x2;
    for(int i = startY; i >= endY; i--)
    {
        grid[i][x++]++;
    }
}

void checkOverlap(int grid[G_SIZE][G_SIZE], int* overlaps)
{
    for(int i = 0; i < G_SIZE; i++)
    {
        for(int j = 0; j < G_SIZE; j++)
        {
            if (grid[i][j] >= 2)
            {
                (*overlaps)++;
            }
        }
    }
}

void printGrid(int grid[G_SIZE][G_SIZE])
{
    for(int i = 0; i < G_SIZE; i++)
    {
        for(int j = 0; j < G_SIZE; j++)
        {
            if(grid[i][j] == 0)
                printf("%c ", '.');
            else
                printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void checkVents(line_segment* lines, int grid[G_SIZE][G_SIZE])
{
    for(int i = 0; i < IN_SIZE; i++)
    {
        if (lines->x1 == lines->x2)
        {
            addVert(*lines, grid);
        }
        else if (lines->y1 == lines->y2)
        {
            addHoriz(*lines, grid);
        }
        else if (abs(lines->x1 - lines->x2) == abs(lines->y1 - lines->y2))
        {
            if((lines->x1 - lines->x2) == (lines->y1 - lines->y2))
            {
                addPosDiag(*lines, grid);
            }
            else
            {
                addNegDiag(*lines, grid);
            }
        }
        lines++;
    }
}

int main(void)
{
    int overlaps;

    int grid[G_SIZE][G_SIZE];
    initGrid(grid);

    line_segment* lines = malloc(sizeof(line_segment)*G_SIZE);
    readLines(lines);

    checkVents(lines, grid);
    checkOverlap(grid, &overlaps);

    
    //printGrid(grid);

    printf("%d\n", overlaps);

    free(lines);
    return 0;
}