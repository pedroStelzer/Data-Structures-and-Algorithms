#include "insertionsort.h"

void insertionsort(vector<int>& list)
{
    int len = list.size();

    for(int i = 1; i < len; i++)
    {
        int num = list[i];
        int j = i-1;

        while(j >= 0 && num < list[j])
        {
            list[j+1] = list[j];
            j--;
        }

        list[j+1] = num;
    }
}