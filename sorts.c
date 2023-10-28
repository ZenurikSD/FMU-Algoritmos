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
int bubbleSort(int *array, int size)
{
    int i, j;
    //int swapped;
    for (i = 0; i < size - 1; i++) {
        //swapped = 0;
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int aux = array[j]; array[j] = array[j + 1]; array[j+1]= aux;
                //swapped = 1;
            }
        }
 
        // If no two elements were swapped
        // by inner loop, then break
        //if (swapped == 0)
        //    break;
    }
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
void heapSort( )
{

}

// Implementado por: Alisson
void mergeSort( )
{

}

//Implementado por: Alisson
int quickSort( )
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