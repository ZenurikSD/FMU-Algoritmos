#ifndef sorts_h
#define sorts_h

//Protótipos das funções de sort

int isSorted(int *array, int size);

void bubbleSort(int *array, int size);

void selectionSort(int *array, int size);

void insertionSort(int *array, int size);

void heapify(int *array, int size, int i);

void heapSort(int *array, int size);

void merge(int *array, int l, int m, int r);

void mergeSort(int *array, int l, int r);

void swap(int *a, int *b);

int partition(int *array, int low, int high);

void quickSort(int *array, int low, int high);

void countSort(int *array, int size);

int findMax(int *array, int size);

void insertInBucket(int *array, int i, int bucket, int min, int range);

void bucketSort(int *array, int size);

int getDigit(int num, int position);

int findMaxDigit(int *array, int n);

void radixSort(int *array, int size);


#endif