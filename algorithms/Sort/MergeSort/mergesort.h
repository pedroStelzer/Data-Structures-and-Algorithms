#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
using namespace std;

void mergesort(vector<int>& list, int start = 0, int end = -1);
void merge(vector<int>& list, int start, int mid, int end);

#endif //MERGESORT_H