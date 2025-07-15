#include "heapsort.h"

void heapsort(vector<int>& list)
{
    int size = list.size();

    MaxHeap obj(size);

    for(int i = 0; i <= size; i++)
        obj.insertKey(list[i]);

    for(int i = size/2 - 1; i >= 0; i--)
        obj.maxHeapify(i);

    for(int j = 0; j < obj.capacity; j++)
        list[j] = obj.extractMax();
}