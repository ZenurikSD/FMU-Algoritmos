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
    int index, j, compare_sum;
    int swapped;
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
   int index,j, compare_sum;
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
   int index, compare_sum;
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