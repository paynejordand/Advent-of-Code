#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int compare(const void *a, const void *b)
{
    return (*(const char *)a - *(const char *)b);
}

int checkChars(char *haystack, char *needle)
{
    int count = 0;
    for (int i = 0; i < strlen(needle); i++)
    {
        if (strchr(haystack, needle[i]))
            count++;
    }
    return count;
}

void mapLetters(char mapping[10][8], char wires[11][8])
{
    for (int i = 0; i < 10; i++)
    {
        switch (strlen(wires[i]))
        {
        case 2:
            strcpy(mapping[1], wires[i]);
            break;
        case 3:
            strcpy(mapping[7], wires[i]);
            break;
        case 4:
            strcpy(mapping[4], wires[i]);
            break;
        case 7:
            strcpy(mapping[8], wires[i]);
            break;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        switch (strlen(wires[i]))
        {
        case 5: // 2, 3, 5
            if (checkChars(wires[i], mapping[1]) == 2)
                strcpy(mapping[3], wires[i]);
            else if (checkChars(wires[i], mapping[4]) == 2)
                strcpy(mapping[2], wires[i]);
            else
                strcpy(mapping[5], wires[i]);
            break;

        case 6: // 0, 6, 9
            if (checkChars(wires[i], mapping[4]) == 4)
                strcpy(mapping[9], wires[i]);
            else if (checkChars(wires[i], mapping[7]) == 2)
                strcpy(mapping[6], wires[i]);
            else
                strcpy(mapping[0], wires[i]);
            break;
        }
    }
}

int displayNum(char display[4][8], char wires[11][8])
{
    for (int i = 0; i < 4; i++)
        qsort(display[i], strlen(display[i]), sizeof(char), compare);

    for (int i = 0; i < 10; i++)
        qsort(wires[i], strlen(wires[i]), sizeof(char), compare);

    char mapping[10][8];

    mapLetters(mapping, wires);

    int num = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (!strcmp(mapping[j], display[i]))
            {
                num += (pow(10, 3 - i) * j);
                break;
            }
        }
    }
    return num;
}

int main(void)
{
    int sum = 0;

    while (!feof(stdin))
    {
        char wires[11][8];
        char display[4][8];
        int i = 0;
        do
        {
            scanf("%s ", wires[i]);
        } while (strcmp(wires[i++], "|") != 0);
        scanf("%s %s %s %s", display[0], display[1], display[2], display[3]);

        sum += displayNum(display, wires);
    }

    printf("%d\n", sum);

    return 0;
}