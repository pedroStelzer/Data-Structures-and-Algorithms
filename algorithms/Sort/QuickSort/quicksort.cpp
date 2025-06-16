#include "quicksort.h"

void quicksort(vector<int>& list, int start, int end)
{
    if(end == -1)
    {
        end = list.size();
    }

    if(start < end)
    {
        int pivot = partition(list, start, end);
        quicksort(list, start, pivot-1);
        quicksort(list, pivot+1, end);
    }
}

int partition(vector<int>& list, int start, int end)
{
    int pivot = list[end];
    int temp;
    int i = start;

    for(int j = start; j < end; j++)
    {
        if(list[j] <= pivot)
        {
            temp = list[i];

            list[i] = list[j];
            list[j] = temp;

            i++;
        }
    }

    temp = list[i];

    list[i] = list[end];
    list[end] = temp;

    return i;
}