#include <stdio.h>
int main()
{
    int nums[3], curr_sum;
    int last_sum = 0;
    int increased = 0;
    int replace = 0;

    FILE* file = fopen("input.txt", "r");

    for(int i = 0; i < 3; i++)
    {
        fscanf(file, " %d ", &nums[i]);
        last_sum += nums[i];
    }
    
    while(!feof(file))
    {
        fscanf(file, " %d ", &nums[replace]);
        curr_sum = nums[0] + nums[1] + nums[2];
        if(curr_sum > last_sum)
            increased++;
        
        last_sum = curr_sum;
        replace = (replace + 1) % 3;
    }
    printf("%d \n", increased);
    fclose(file);

    return 0;
}