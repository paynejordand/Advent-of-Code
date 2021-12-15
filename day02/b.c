#include <stdio.h>

int main(void)
{
    int depth = 0;
    int aim = 0;
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
                depth += (aim * dist);
                break;
            case 'u':
                aim -= dist;
                break;
            case 'd':
                aim += dist;
                break;
        }
    }

    printf("%d\n", depth*horiz);
    return 0;
}