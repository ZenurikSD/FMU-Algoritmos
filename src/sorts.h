#ifndef sorts_h
#define sorts_h

//Protótipos das funções de sort

int isSorted(int *array, int size);

int bubbleSort(int *array, int size);

int selectionSort(int *array, int size);

int insertionSort(int *array, int size);

int heapify(int *array, int size, int i, long compare_sum);

int heapSort(int *array, int size);

int mergeSort( );

int quickSort( );

int countSort( );

int bucketSort( );

int radixSort( );


#endif