#include <stdio.h>
int main()
{
    int curr_sum, last_sum;
    int nums[3] = {9999, 9999, 9999};
    int increased = 0;
    int replace = 0;

    FILE* file = fopen("input.txt", "r");
    
    while(!feof(file))
    {
        fscanf(file, "%d ", &nums[replace]);
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