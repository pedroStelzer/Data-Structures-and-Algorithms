#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
using namespace std;

void quicksort(vector<int>& list, bool decrease_order = false, int start = 0, int end = -1);
int partition(vector<int>& list, bool decrease_order, int start, int end);

#endif //QUICKSORT_H