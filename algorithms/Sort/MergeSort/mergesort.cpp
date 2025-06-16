#include "mergesort.h"

void mergesort(vector<int>& list, int start, int end)
{
    if(end == -1)
    {
        end = list.size()-1;
    }
    
    if(start < end)
    {
        int mid = (start + end)/2;

        mergesort(list, start, mid);
        mergesort(list, mid+1, end);

        merge(list, start, mid, end);
    }
}

void merge(vector<int>& list, int start, int mid, int end)
{
    vector<int> left;
    vector<int> right;

    for(int i = start; i <= mid; i++)
        left.push_back(list[i]);
    
    for(int i = mid+1; i <= end; i++)
        right.push_back(list[i]);
    
    int l = 0;
    int r = 0;
    int k = start;

    int left_size = left.size();
    int right_size = right.size();

    while(l < left_size && r < right_size)
    {
        if(left[l] <= right[r])
        {
            list[k] = left[l];
            l++;
        }
        else
        {
            list[k] = right[r];
            r++;
        }

        k++;
    }

    while(l < left_size)
    {
        list[k] = left[l];
        l++;
        k++;
    }

    while(r < right_size)
    {
        list[k] = right[r];
        r++;
        k++;
    }
}