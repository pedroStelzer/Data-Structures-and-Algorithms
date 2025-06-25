#include "selectionsort.h"

void selectionsort(vector<int>& nums)
{
    int len = nums.size();

    for(int i = 0; i < len; i++)
    {
        int num = nums[i];
        int index = i;

        for(int j = i; j < len; j++)
        {
            if(num > nums[j])
            {
                num = nums[j];
                index = j;
            }
        }

        int aux = nums[i];
        nums[i] = num;
        nums[index] = aux;
    }
}