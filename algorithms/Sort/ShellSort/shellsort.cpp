#include "shellsort.h"

void shellsort(vector<int>& list)
{
    int len = list.size();

    int k = floor(log(len/2 + 1) / log(3) + 0.5);
    int h = (pow(3, k) - 1) / 2;

    while(h > 0)
    {
        for(int i = h; i < len; i++)
        {
            int num = list[i];
            int j = i;

            while(j >= h && num < list[j-h])
            {
                list[j] = list[j-h];
                j -= h;
            }

            list[j] = num;
        }

        h = (h - 1) / 3;
    }
}