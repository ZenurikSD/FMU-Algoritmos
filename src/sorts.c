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

// Implementado por: Gui Lindão
void bubbleSort(int *array, int size) {
    int index, j;
    int swapped;
    for (index = 0; index < size - 1; index++) {
        swapped = 0;
        for (j = 0; j < size - index - 1; j++) {
            if (array[j] > array[j + 1]) { // se elemento for menor que o seguinte, troca
                int aux = array[j]; 
                array[j] = array[j + 1];
                array[j+1]= aux;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

// Implementado por: Gui
void selectionSort(int *vetor, int size) {
   int index,j;
   for (index = 0; index < size-1; ++index) {
      int min = index; // vai procurar elemento que deve ir na posição index
      for (j = index+1; j < size; ++j) // procura o menor elemento
         if (vetor[j] < vetor[min])  min = j;
      int x = vetor[index]; vetor[index] = vetor[min]; vetor[min] = x; // coloca o elemento no local certo
   }
}

// Implementado por: Gui
// Esta função rearranja o vetor v[0..n-1]
// em ordem crescente.
void insertionSort (int *vetor, int size) {
   int index;
   for ( index = 1; index < size; ++index) {
      int x = vetor[index]; // valor da nova posição do vetor j, que será inserida
      int i;
      for (i = index-1; i >= 0 && vetor[i] > x; --i) // desloca o elemento para a esquerda enquando é menor
         vetor[i+1] = vetor[i];
      vetor[i+1] = x; // insere o elemento na posição correta
   }
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