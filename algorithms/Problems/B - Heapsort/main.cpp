#include <iostream>
#include <math.h>

using namespace std;

class MaxHeap
{
    private:

        int *harr;
        int capacity;
        int heapSize;

    public:

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

int main()
{
    int s;
    
    cout << "Enter Size of Max Heap" << endl;
    cin >> s;

    MaxHeap obj(s);

    cout << "Max Heap Created" << endl;

    int option, val;

    do
    {
        cout << "What operation do you want to perform"
        << "Select Option number. Enter 0 to exit." << endl;

        cout << "1. Insert Key/Node/value" << endl;
        cout << "2. Search Key/Node" << endl;
        cout << "3. Delete Key/Node" << endl;
        cout << "4. Get Max" << endl;
        cout << "5. Extract Max" << endl;
        cout << "6. Height of Heap" << endl;
        cout << "7. Print/Traversal Heap values" << endl;
        cout << "8. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;

        switch (option)
        {
            case 0:
                break;

            case 1:

                cout << "INSERT Operation -" << endl;
                cout << "Enter VALUE to INSERT in HEAP: ";
                cin >> val;

                obj.insertKey(val);

                cout << endl;
                break;
            
            case 2:

                cout << "SEARCH Operation -" << endl;
                cout << "Enter VALUE to SEARCH in HEAP: ";
                cin >> val;

                obj.linearSearch(val);

                break;
            
            case 3:

                cout << "DELETE Operation -" << endl;
                cout << "Enter INDEX of Heap Array to DELETE: ";
                cin >> val;

                obj.deleteKey(val);

                cout << endl;
                break;
            
            case 4:

                cout << "GET Max value: " << endl;
                cout << obj.getMax() << endl;
                
                cout << endl;
                break;
            
            case 5:

                cout << "EXTRACT Max value: " << endl;
                cout << obj.extractMax() << endl;
                
                cout << endl;
                break;
            
            case 6:

                cout << "HEAP TREE HEIGHT: " << endl;
                cout << obj.getMax() << endl;
                
                cout << endl;
                break;
            
            case 7:

                cout << "PRINT Heap Array: " << endl;
                obj.printArray();
                
                cout << endl;
                break;
            
            case 8:
                
                system("cls");
                break;

            default:

                cout << "Enter Proper Option number" << endl;
                break;
        }
    } while (option != 0);
    
    return 0;
}