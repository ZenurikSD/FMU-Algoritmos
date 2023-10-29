#include <stdio.h>
#include <stdlib.h>

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
void selectionSort(int *array, int size) {
   int index,j;
   
   for (index = 0; index < size-1; ++index) {
      int min = index; // vai procurar elemento que deve ir na posição index
      for (j = index+1; j < size; ++j) // procura o menor elemento
         if (array[j] < array[min]){
            min = j;
         }
            
      int x = array[index]; array[index] = array[min]; array[min] = x; // coloca o elemento no local certo
   }
}

// Implementado por: Gui
void insertionSort(int *array, int size) {
   int index;
   
   for ( index = 1; index < size; ++index) {
      int x = array[index]; // valor da nova posição do vetor j, que será inserida
      int i;

      for (i = index-1; i >= 0 && array[i] > x; --i){  // desloca o elemento para a esquerda enquando é menor
         array[i+1] = array[i];
      } 
      array[i+1] = x; // insere o elemento na posição correta
   }
}

//(Heap sort)
void heapify(int *array, int size, int i) 
{
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < size && array[left] > array[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < size && array[right] > array[largest]) {
        largest = right;
    }

    // If the largest element is not the root
    if (largest != i) {
        // Swap array[i] and array[largest]
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(array, size, largest);
    }
}

//Implementado por: Alisson
void heapSort(int *array, int size)
{
    

    // Build a max heap
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(array, size, i);
    }

    // One by one extract elements from the heap
    for (int i = size - 1; i >= 0; i--) {
        

        // Move the current root to the end
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        // Call max heapify on the reduced heap
        heapify(array, i, 0);
    }
}

// (Merge sort)
void merge(int *array, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++) {
        L[i] = array[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = array[m + 1 + j];
    }

    // Merge the temp arrays back into array[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }

    // Free the temporary arrays
    free(L);
    free(R);
}

// Implementado por: Alisson
void mergeSort(int *array, int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);

        // Merge the sorted halves
        merge(array, l, m, r);
    }
}

// (Quick-sort)
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// (Quick-sort)
int partition(int *array, int low, int high) {
    int pivot = array[high]; // Choose the rightmost element as the pivot
    int i = (low - 1);     // Initialize the index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (array[j] <= pivot) {
            i++; // Increment the index of the smaller element
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1); // Return the index of the pivot
}

//Implementado por: Alisson
void quickSort(int *array, int low, int high)
{
    if (low < high) {
        int pivot = partition(array, low, high); // Get the pivot element such that
        quickSort(array, low, pivot - 1);       // elements smaller than pivot are on the left
        quickSort(array, pivot + 1, high);      // elements greater than pivot are on the right
    }
}

//Implementado por: Gilberto
void countSort(int *array, int n) {
    int max = array[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int *count = (int *)malloc((max + 1) * sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));
    if (count == NULL || output == NULL) {
        printf("Falha na alocação de memória.\n");
        return;
    }
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        count[array[i]]++;
    }
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
    for (int i = 0; i < n; i++) {
        array[i] = output[i];
    }
    free(count);
    free(output);
}

//Implementado por:
int bucketSort( )
{

}

//Implementado por: Gilberto
int getDigit(int num, int position) { // Função para encontrar o dígito na posição especificada
    int divider = 1;
    for (int i = 0; i < position; i++) {
        divider *= 10;
    }
    return (num / divider) % 10;
}
int findMaxDigit(int *array, int n) { // Função para encontrar o dígito mais significativo no vetor
    int max = array[0];
    for (int i = 1; i < n; i++) { // Encontre o valor máximo no vetor
        if (array[i] > max) {
            max = array[i];
        }
    }
    int digitCount = 0;
    while (max > 0) { // Conte o número de dígitos em max
        max /= 10;
        digitCount++;
    }
    return digitCount; // Retorna o número de dígitos no número máximo
}
// Função de ordenação Radix Sort
void radixSort(int *array, int n) {
    int maxDigit = findMaxDigit(array, n);
    for (int position = 0; position < maxDigit; position++) { // Percorra cada posição dos dígitos, do menos significativo ao mais significativo
        int output[n]; // Crie um vetor de saída para armazenar os resultados ordenados
        int count[10] = {0};// Inicialize um vetor de contagem para os dígitos de 0 a 9
        // Conte a ocorrência de cada dígito na posição atual
        for (int i = 0; i < n; i++) {
            int digit = getDigit(array[i], position);
            count[digit]++;
        }
        // Atualize o vetor de contagem para conter as posições corretas no vetor de saída
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        // Coloque os elementos do vetor de entrada nas posições corretas do vetor de saída
        for (int i = n - 1; i >= 0; i--) {
            int digit = getDigit(array[i], position);
            output[count[digit] - 1] = array[i];
            count[digit]--;
        }
        // Copie os elementos ordenados de volta para o vetor de entrada
        for (int i = 0; i < n; i++) {
            array[i] = output[i];
        }
    }
}
