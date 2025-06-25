#include "bubblesort.h"

void bubblesort(vector<int>& nums)
{
    int len = nums.size();
    int i = 0;
    bool sorted = true;

    do
    {
        sorted = true;

        for(int j = 0; j < len-1; j++)
        {
            if(nums[j] > nums[j+1])
            {
                int aux = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = aux;
                sorted = false;
            }
        }
        i++;
    } 
    while(!sorted && i < len);
}