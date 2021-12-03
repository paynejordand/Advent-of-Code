#include <stdio.h>

int main(void)
{
    int depth = 0;
    int horiz = 0;
    int dist;
    char dir[7];

    while(!feof(stdin))
    {
        scanf("%s %d ", dir, &dist);
        
        switch(dir[0])
        {
            case 'f':
                horiz += dist;
                break;
            case 'u':
                depth -= dist;
                break;
            case 'd':
                depth += dist;
                break;
        }
    }

    printf("%d\n", depth*horiz);
    return 0;
}