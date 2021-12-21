#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SIZE 100 // test:10 input:100

typedef struct
{
    uint32_t i;
    uint32_t j;
    uint32_t visited;
    uint32_t weight;
} node;

int node_cmp(const void *a, const void *b)
{
    node l = *(node *)a;
    node r = *(node *)b;

    if (l.visited > r.visited)
        return 1;
    else if (l.visited < r.visited)
        return -1;

    if (l.weight > r.weight)
        return 1;
    else if (l.weight < r.weight)
        return -1;

    if (l.i > r.i)
        return 1;
    else if (l.i < r.i)
        return -1;

    if (l.j > r.j)
        return 1;

    return -1;
}

typedef struct
{
    uint32_t count;
    uint32_t notVisited;
    node visited[SIZE * SIZE];
} set;

int set_contains(set s, uint32_t i, uint32_t j)
{
    for (int k = 0; k < s.count; k++)
    {
        if ((s.visited[k].i == i) && (s.visited[k].j == j))
            return k;
    }
    return -1;
}

set set_copy(set s)
{
    set new;
    for (int i = 0; i < s.count; i++)
    {
        new.visited[i].i = s.visited[i].i;
        new.visited[i].j = s.visited[i].j;
        new.visited[i].visited = s.visited[i].visited;
        new.visited[i].weight = s.visited[i].weight;
    }
    new.count = s.count;
    return new;
}

void set_clear(set *s)
{
    s->count = 0;
    s->notVisited = 0;
}

void set_add(set *s, uint32_t i, uint32_t j, uint32_t v, uint32_t w)
{
    if (set_contains(*s, i, j) < 0)
    {
        uint32_t count = s->count++;
        s->visited[count].i = i;
        s->visited[count].j = j;
        s->visited[count].visited = v;
        s->visited[count].weight = w;
    }
}

void orderSet(set *s)
{
    qsort(s->visited, s->count, sizeof(node), node_cmp);
    uint32_t i = 0;
    s->notVisited = 0;
    for (; i < s->count; i++)
    {
        if (s->visited[i].visited)
            s->notVisited++;
    }
}

void getWeights(uint32_t grid[SIZE][SIZE], set *s, uint32_t i, uint32_t j, uint32_t w[4])
{
    w[0] = (i == 0) ? 0 : grid[i - 1][j];
    w[1] = (j == SIZE - 1) ? 0 : grid[i][j + 1];
    w[2] = (i == SIZE - 1) ? 0 : grid[i + 1][j];
    w[3] = (j == 0) ? 0 : grid[i][j - 1];
}

void dijkstra(uint32_t grid[SIZE][SIZE], set *s)
{
    while (1)
    {
        node *n = &(s->visited[0]);
        n->visited = 1;
        uint32_t weights[4];
        getWeights(grid, s, n->i, n->j, weights);

        for (uint8_t i = 0; i < 4; i++)
        {
            if (!weights[i])
                continue;

            uint32_t tmpI, tmpJ;
            switch (i)
            {
            case 0:
                tmpI = n->i - 1;
                tmpJ = n->j;
                break;
            case 1:
                tmpI = n->i;
                tmpJ = n->j + 1;
                break;
            case 2:
                tmpI = n->i + 1;
                tmpJ = n->j;
                break;
            case 3:
                tmpI = n->i;
                tmpJ = n->j - 1;
                break;
            }

            node *next_node = &(s->visited[set_contains(*s, tmpI, tmpJ)]);
            if (next_node->visited)
                continue;
            if ((n->weight + weights[i]) < next_node->weight)
                next_node->weight = (n->weight + weights[i]);
        }
        orderSet(s);
        if (s->notVisited == s->count)
            break;
    }
}

int main(void)
{
    uint32_t grid[SIZE][SIZE];
    set visited;
    set_clear(&visited);

    for (uint32_t i = 0; i < SIZE; i++)
    {
        char c;
        for (uint32_t j = 0; j < SIZE; j++)
        {
            scanf("%c", &c);
            grid[i][j] = c - '0';
            uint32_t weight = ((i + j) == 0) ? 0 : UINT32_MAX;
            set_add(&visited, i, j, 0, weight);
        }
        scanf("\r\n");
    }

    dijkstra(grid, &visited);

    printf("%u\n", visited.visited[set_contains(visited, SIZE - 1, SIZE - 1)].weight);

    return 0;
}