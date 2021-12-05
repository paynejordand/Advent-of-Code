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

void addHoriz(int x, int y1, int y2, int grid[G_SIZE][G_SIZE])
{
    for(int i = y1; i <= y2; i++)
    {
        grid[x][i]++;
    }
}

void addVert(int y, int x1, int x2, int grid[G_SIZE][G_SIZE])
{
    for(int i = x1; i <= x2; i++)
    {
        grid[i][y]++;
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

void checkVents(line_segment* lines, int grid[G_SIZE][G_SIZE], int* overlaps)
{
    for(int i = 0; i < IN_SIZE; i++)
    {
        if (lines->x1 == lines->x2)
        {
            addVert(lines->x1, fmin(lines->y1, lines->y2), fmax(lines->y1, lines->y2), grid);
        }
        else if (lines->y1 == lines->y2)
        {
            addHoriz(lines->y1, fmin(lines->x1, lines->x2), fmax(lines->x1, lines->x2), grid);
        }
        lines++;
    }
    checkOverlap(grid, overlaps);
}

int main(void)
{
    int overlaps;

    int grid[G_SIZE][G_SIZE];
    initGrid(grid);

    line_segment* lines = malloc(sizeof(line_segment)*G_SIZE);

    readLines(lines);

    checkVents(lines, grid, &overlaps);
    
    //printGrid(grid);

    printf("%d\n", overlaps);

    free(lines);
    return 0;
}