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

// Implementado por: Gui Lindão
int bubbleSort(int *array, int size) {
    int index, j;
    int swapped;
    long compare_sum;
    for (index = 0; index < size - 1; index++) {
        swapped = 0;
        for (j = 0; j < size - index - 1; j++) {
            if (array[j] > array[j + 1]) { // se elemento for menor que o seguinte, troca
                int aux = array[j]; 
                array[j] = array[j + 1];
                array[j+1]= aux;
                swapped = 1;
                compare_sum++;
            }
        }
        if (swapped == 0)
            break;
    }

    return compare_sum;
}

// Implementado por: Gui
int selectionSort(int *array, int size) {
   int index,j;
   long compare_sum;
   
   for (index = 0; index < size-1; ++index) {
      int min = index; // vai procurar elemento que deve ir na posição index
      for (j = index+1; j < size; ++j) // procura o menor elemento
         if (array[j] < array[min]){
            min = j;
            compare_sum++;
         }
            
      int x = array[index]; array[index] = array[min]; array[min] = x; // coloca o elemento no local certo
   }

   return compare_sum;
}

// Implementado por: Gui
int insertionSort(int *array, int size) {
   int index;
   long compare_sum;

   for ( index = 1; index < size; ++index) {
      int x = array[index]; // valor da nova posição do vetor j, que será inserida
      int i;

      for (i = index-1; i >= 0 && array[i] > x; --i){  // desloca o elemento para a esquerda enquando é menor
         array[i+1] = array[i];
         compare_sum++;
      } 
      array[i+1] = x; // insere o elemento na posição correta
   }
}

//(Heap sort)
int heapify(int *array, int size, int i, long compare_sum) 
{
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < size && array[left] > array[largest]) {
        largest = left;
        compare_sum++;
    }

    // If right child is larger than largest so far
    if (right < size && array[right] > array[largest]) {
        largest = right;
        compare_sum++;
    }

    // If the largest element is not the root
    if (largest != i) {
        // Swap array[i] and array[largest]
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(array, size, largest, compare_sum);
        compare_sum++;
    }

    return compare_sum;
}

//Implementado por: Alisson
int heapSort(int *array, int size)
{
    long compare_sum;

    // Build a max heap
    for (int i = size / 2 - 1; i >= 0; i--) {
        compare_sum += heapify(array, size, i, compare_sum);
    }

    // One by one extract elements from the heap
    for (int i = size - 1; i >= 0; i--) {
        

        // Move the current root to the end
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        // Call max heapify on the reduced heap
        compare_sum += heapify(array, i, 0, compare_sum);
    }

    return compare_sum;
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