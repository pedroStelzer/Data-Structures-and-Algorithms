#include "quicksort.h"

// QuickSort com opcao de ordem decrescente
void quicksort(vector<int>& list, bool decrease_order, int start, int end)
{
    if(end == -1) // valor padrao para a primeira chamada
        end = list.size()-1;

    if(start < end)
    {
        int pivot = partition(list, decrease_order, start, end);
        quicksort(list, decrease_order, start, pivot-1);   // esquerda do pivot
        quicksort(list, decrease_order, pivot+1, end);     // direita do pivot
    }
}

// Particao usando Lomuto
int partition(vector<int>& list, bool decrease_order, int start, int end)
{
    int pivot = list[end]; // ultimo elemento como pivot
    int temp;
    int i = start;

    for(int j = start; j < end; j++)
    {
        // Comparacao depende da ordem escolhida
        if((!decrease_order && list[j] >= pivot) // crescente
        || (decrease_order && list[j] <= pivot)) // decrescente
        {
            // troca o elemento da posicao atual 
            temp = list[i];
            list[i] = list[j];
            list[j] = temp;
            i++;
        }
    }

    // Coloca o pivot na posicao i
    temp = list[i];
    list[i] = list[end];
    list[end] = temp;

    return i;
}