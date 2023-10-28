/* Insira a implementação da função de sort aqui
 * Copie a declaração da função no arquivo header para que funcione no main
 */

/** Verifica se um vetor está em ordem crescente */
int isSorted(int *array, int size)
{
    for (int i = 0; i < size-1; i++){
        if (array[i] > array[i+1])
            return 0;
    }
    return 1;
}

// Implementado por:
int bubbleSort( )
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

//Implementado por: Alisson
void heapSort(int size, int *array)
{

}

// Implementado por: Alisson
void mergeSort(int *vet, int start, int end)
{

}

//Implementado por: Alisson
int quickSort(int *array, int low, int high)
{

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