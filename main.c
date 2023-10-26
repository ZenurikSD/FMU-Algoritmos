/* TO-DO:
 * 1. Implementar algoritmos de ordenação
 * 2. Implementar código para gerar vetores e salvar eles em um arquivo para comparar o 
 *    desempenho dos algoritmos com o mesmo vetor
 */

#include <stdio.h>
#include <stdlib.h>

/** Troca duas posições inteiras de um vetor */
int swapArrayInts(int *arr, int i, int j)
{
    int aux = arr[i];
    int arr[i] = arr[j];
    int arr[j] = arr[i];
}

// Implementado por:
void bubbleSort( )
{

}

// Implementado por:
void selectionSort( )
{

}

// Implementado por:
void insertionSort( )
{

}

//(Heap sort) Implementado por: Alisson
void buildHeap(int size, int *array)
{
    for(int c1 = 1; c1 < size; c1++)
    {
        int c2 = c1 + 1;

        while (c2 > 1 && (array[c2 / 2] > array[c2]) )
        {
            int aux = array[c2];
            array[c2] = array[c2 / 2];
            array[c2 / 2] = aux;

            c2 /= 2;
        }
    }


}

//(Heap sort) Implementado por: Alisson
void rebalanceHeap(int size, int *array)
{
    int cmax = 2;
    int aux;

    while (cmax <= size)
    {
        if (cmax < size && (array[cmax] < array[cmax + 1]))
            cmax++;

        aux = array[cmax];
        array[cmax] = array[cmax + 1];
        array[cmax + 1] = aux;

        cmax *= 2;
    }
}

//Implementado por: Alisson
void heapSort(int size, int *array)
{
    int last_index, aux;
    buildHeap(size, array);

    for (last_index = size; last_index >= 2; last_index--)
    {
        aux = array[1];
        array[1] = array[last_index];
        array[last_index] = aux;

        rebalanceHeap(last_index - 1, array);
    }
}

// Implementado por: Alisson
void mergeSort(int *vet, int start, int end)
{

}

//(Quick sort) Implementado por: Alisson
int partition(int *array, int low, int high)
{
    int pivot = array[high];

    int i = low - 1;
    int aux;
    for (int j = low; j < high; j++)
    {
        if (array[j] < pivot){
            i++;
            swapArrayInts(array, i, j);
        }
    }

    swapArrayInts(array, i+1, high);
    return i + 1;
}

//Implementado por: Alisson
int quickSort(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(array, low, high);

        //Repita o processo nos subvetores esquerdo e direito
        quickSort(array, low, pivot_index - 1);
        quickSort(array, pivot_index + 1, high);
    }
}

//Implementado por:
void countSort( )
{

}

//Implementado por:
void bucketSort( )
{

}

//Implementado por:
void radixSort( )
{

}

int main(void)
{
    // TO-DO's:

    // gerar um vetor aleatório de tamanho definido pelo usuário

    // fazer uma verificação de quando o vetor está desordenado e ordenado

    // permitir ao usuário escolher o algoritmo a ordenar

    // exibir o tempo de execução do algoritmo
}