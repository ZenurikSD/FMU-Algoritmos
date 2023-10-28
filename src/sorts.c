#include <stdio.h>

/* Insira a implementação da função de sort aqui
 * Copie a declaração da função no arquivo header para que funcione no main
 * Todos os sorts precisam ter um retorno do número de comparações IF que fazem
 */

/** Verifica se um vetor está em ordem crescente */
int isSorted(int *array, int size)
{
    for (int i = 1; i < size; i++){
        if (array[i - 1] > array[i]){
            return 0;
        }
    }
    return 1;
}

// Implementado por:
void bubbleSort(int *array, int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Implementado por:
int selectionSort( )
{

}

// Implementado por:
int insertionSort( )
{

}

//Implementado por: Alisson
int heapSort( )
{

}

// Implementado por: Alisson
int mergeSort( )
{

}

//Implementado por: Alisson
int quickSort( )
{

}

//Implementado por:
int countSort( )
{

}

//Implementado por:
int bucketSort( )
{

}

//Implementado por:
int radixSort( )
{

}