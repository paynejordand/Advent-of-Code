#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int letterCount[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char display[4][8];

    while(!feof(stdin))
    {
        char wires[11][8];
        int i = 0;
        do
        {
            scanf("%s ", wires[i]);
        } while (strcmp(wires[i++], "|") != 0);
        scanf("%s %s %s %s", display[0], display[1], display[2], display[3]);

        for(int i = 0; i < 4; i++)
        {
            switch(strlen(display[i]))
            {
                case 2:
                    letterCount[1]++;
                    break;
                case 3:
                    letterCount[7]++;
                    break;
                case 4: 
                    letterCount[4]++;
                    break;
                case 7:
                    letterCount[8]++;
                    break;
                default:
                    break;
            }
        }
    }

    printf("%d\n", letterCount[1] + letterCount[4] + letterCount[7] + letterCount[8]);    
    return 0;
}