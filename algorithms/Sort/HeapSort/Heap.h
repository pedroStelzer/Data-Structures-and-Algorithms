#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <math.h>

using namespace std;

class MaxHeap
{
    public:

        int *harr;
        int capacity;
        int heapSize;

        MaxHeap(int cap) 
        {
            heapSize = 0;
            capacity = cap;
            harr = new int[cap];
        };

        ~MaxHeap() {};

        int parent(int i)
        {
            return (i-1)/2;
        };

        int left(int i)
        {
            return (2*i + 1);
        };

        int right(int i)
        {
            return (2*i + 2);
        };

        int getMax()
        {
            return harr[0];
        };

        int extractMax()
        {
            if(heapSize <= 0)
                return __INT_MAX__;

            if(heapSize == 1)
            {
                heapSize--;
                return harr[0];
            }

            int root = harr[0];

            harr[0] = harr[heapSize-1];
            heapSize--;

            maxHeapify(0);

            return root;
        };

        void insertKey(int k)
        {
            if(heapSize == capacity)
            {
                cout << "\nOverflow: Heap full\n";
                return;
            }

            heapSize++;

            int i = heapSize-1;

            harr[i] = k;

            while(i != 0 && harr[parent(i)] < harr[i])
            {   
                int temp = harr[i];
                harr[i] = harr[parent(i)];
                harr[parent(i)] = temp;

                i = parent(i);
            }
        };

        void increaseKey(int i, int newVal)
        {
            harr[i] = newVal;

            while(i != 0 && harr[parent(i)] < harr[i])
            {
                int temp = harr[i];
                harr[i] = harr[parent(i)];
                harr[parent(i)] = temp;

                i = parent(i);
            }
        };

        void deleteKey(int i)
        {
            increaseKey(i, __INT_MAX__);
            extractMax();
        };

        void maxHeapify(int i)
        {
            int l = left(i);
            int r = right(i);

            int largest = i;

            if(l < heapSize && harr[l] > harr[i])
                largest = l;
            
            if(r < heapSize && harr[r] > harr[largest])
                largest = r;

            if(largest != i)
            {
                int temp = harr[i];
                harr[i] = harr[largest];
                harr[largest] = temp;

                maxHeapify(largest);
            }
        };

        void linearSearch(int val)
        {
            for(int i = 0; i < heapSize; i++)
            {
                if(harr[i] == val)
                {
                    cout << "Value found";
                    return;
                }

                cout << "Value not found";
            }
        };

        void printArray()
        {
            for(int i = 0; i < heapSize; i++)
                cout << harr[i] << " ";
            
            cout << endl;
        };

        int height()
        {
            return ceil(log2(heapSize+1)-1);
        };
};

#endif //HEAP_H