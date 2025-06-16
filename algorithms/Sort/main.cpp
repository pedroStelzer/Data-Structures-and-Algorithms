#include <iostream>
#include <vector>
#include <chrono>
#include <math.h>
#include "MergeSort/mergesort.h"
#include "QuickSort/quicksort.h"

using namespace std;
using namespace std::chrono;

vector<int> sequence_gerenate(int n, int seed = 42)
{
    int a = 1664525;
    int c = 1013904223;
    int m = pow(2, 30);
    int x = seed;
    vector<int> list;

    for(int i = 0; i < n; i++)
    {
        x = (a * x + c) % m;
        list.push_back(x % 10000);
    }

    return list;
}

int main()
{
    vector<int> nums;

    int n = 0;

    while(n >= 0)
    {
        cout << "Quantidade de iteracoes: ";
        cin >> n;

        nums = sequence_gerenate(n);

        auto start_time = high_resolution_clock::now();

        mergesort(nums);
        //quicksort(nums);

        /*for(int i = 0; i < n; i++)
            cout << nums[i] << endl;*/
        
        auto end_time = high_resolution_clock::now();

        auto final_time = duration_cast<nanoseconds>(end_time - start_time);

        cout << "Tempo de execucao: " << final_time.count() << " ns" << endl << endl;
    }

    return 0;
}