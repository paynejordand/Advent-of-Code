#include <stdio.h>
#include <math.h>


void countBits(int* matches, char bits[][13], int* bitCount, int index)
{
    for (int i = 0; i < 1000; i++)
        if (matches[i])
            bitCount[bits[i][index] - '0'] += 1;
}

void checkBits(int* matches, char bits[][13], char bitCriteria, int index, int* matchCount, int* lastMatch)
{
    for(int i = 0; i < 1000; i++)
    {
        if (matches[i])
        {
            if (bits[i][index] != bitCriteria)
            {
                matches[i] = 0;
                (*matchCount)--;
            }
            else
                (*lastMatch) = i;
        }
    }
}

int binToDec(char * bin)
{
    int dec = 0;
    for(int i = 0; i < 12; i++)
        dec += ((bin[i]-'0') * pow(2, 11-i));
    return dec;
}

int main(void)
{
    int oxygen = 0;
    int carbon = 0;

    char line[1000][13];
    // gcc specifc array init
    int oMatches[1000] = {[0 ... 999] = 1};
    int oCount = 1000;

    int cMatches[1000] = {[0 ... 999] = 1};
    int cCount = 1000;

    int count = 0;
    int lastMatch = 0;

    while(!feof(stdin))
    {
        scanf("%s ", line[count]);
        count++;
    }

    for(int i = 0; i < 12; i++)
    {
        int bitCount[2] = {0, 0};
        countBits(oMatches, line, bitCount, i);
        char criteria = (bitCount[1] >= bitCount[0]) + '0';
        checkBits(oMatches, line, criteria, i, &oCount, &lastMatch);
        if (oCount == 1)
        {
            oxygen = binToDec(line[lastMatch]);
            break;
        }
    }

    for(int i = 0; i < 12; i++)
    {
        int bitCount[2] = {0, 0};
        countBits(cMatches, line, bitCount, i);
        char criteria = (bitCount[1] < bitCount[0]) + '0';
        checkBits(cMatches, line, criteria, i, &cCount, &lastMatch);
        if (cCount == 1)
        {
            carbon = binToDec(line[lastMatch]);
            break;
        }
    }


    printf("%d\n", oxygen * carbon);

    return 0;
}