#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define C_I_OFFSET 65

int intcmp(const void *a, const void *b)
{
    uint64_t l = *(uint64_t *)a;
    uint64_t r = *(uint64_t *)b;

    return l > r;
}

typedef struct
{
    char pair[3];
    char insert;
    uint64_t count;
} pair_insert;

void addPairs(pair_insert *pairs, char pair[3], uint64_t count, const int numPairs)
{
    for (int i = 0; i < numPairs; i++)
    {
        if (!strcmp(pairs[i].pair, pair))
        {
            pairs[i].count += count;
            return;
        }
    }
}

void patternAdd(pair_insert *pairs, uint64_t l[26], int index, uint64_t count, const int numPairs)
{
    char temp[3];
    pairs[index].count -= count;
    l[pairs[index].insert - C_I_OFFSET] += count;
    temp[0] = pairs[index].pair[0];
    temp[1] = pairs[index].insert;
    temp[2] = '\0';
    addPairs(pairs, temp, count, numPairs);

    temp[0] = pairs[index].insert;
    temp[1] = pairs[index].pair[1];
    temp[2] = '\0';
    addPairs(pairs, temp, count, numPairs);
    return;
}

int main(void)
{
    uint64_t letters[26];
    char template[21];
    pair_insert pairs[100];
    int numPairs = 0;

    for (int i = 0; i < 26; i++)
    {
        letters[i] = 0;
    }

    scanf("%s ", template);

    while (!feof(stdin))
    {
        scanf("%s -> %c ", pairs[numPairs].pair, &pairs[numPairs].insert);
        pairs[numPairs].count = 0;
        numPairs++;
    }

    for (int i = 0; i < strlen(template) - 1; i++)
    {
        char temp[3];
        temp[0] = template[i];
        temp[1] = template[i + 1];
        temp[2] = '\0';
        addPairs(pairs, temp, 1, numPairs);
        letters[template[i] - C_I_OFFSET]++;
    }
    letters[template[strlen(template) - 1] - C_I_OFFSET]++;

    for (int i = 0; i < 40; i++)
    {
        pair_insert tempPairs[100];
        memcpy(tempPairs, pairs, sizeof(pair_insert) * numPairs);

        for (int j = 0; j < numPairs; j++)
        {
            uint64_t count;
            if ((count = tempPairs[j].count))
            {
                patternAdd(pairs, letters, j, count, numPairs);
            }
        }
    }

    qsort(letters, 26, sizeof(uint64_t), intcmp);

    uint64_t min = 0;
    for (int i = 0; i < 26; i++)
    {
        if (letters[i] != 0)
        {
            min = letters[i];
            break;
        }
    }

    printf("%lu\n", letters[25] - min);

    return 0;
}