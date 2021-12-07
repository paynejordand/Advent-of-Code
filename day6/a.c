#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int count = 300;
    int alloc = count;
    int* states = malloc(sizeof(int) * alloc);

    int i = 0;
    while(!feof(stdin))
    {
        scanf("%d,", &states[i++]);
    }

    for(i = 1; i <= 80; i++)
    {
        int new = 0;
        printf("After %4d days: ", i);
        for(int j = 0; j < count; j++)
        {
            states[j]--;
            if(states[j] == -1)
            {
                states[j] = 6;
                new++;
            }        
        }
        if(new + count > alloc)
        {
            alloc *= 2;
            states = realloc(states, sizeof(int) * alloc);
        }
        for(int j = 0; j < new; j++)
        {
            states[count++] = 8;
        }
        // for(int j = 0; j < count; j++)
        // {
        //     printf("%d, ", states[j]);
        // }
        printf("\n");
    }

    printf("%d\n", count);

    free(states);
    return 0;
}