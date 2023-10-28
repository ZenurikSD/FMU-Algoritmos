#ifndef sorts_h
#define sorts_h

//Protótipos das funções de sort

int isSorted(int *array, int size);

int bubbleSort(int *array, int size);

void selectionSort(int *vetor, int size);

void insertionSort(int *vetor, int size );

void heapSort(int size, int *array);

void mergeSort(int *vet, int start, int end);

int quickSort(int *array, int low, int high);

void countSort( );

void bucketSort( );

void radixSort( );


#endif
