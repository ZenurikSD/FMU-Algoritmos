#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sorts.h"

//Armazena o nome do algoritmo usado e a soma das comparações feitas por ele
typedef struct results{
    char *sortname;
    long comparesum;
} results;

int readArray(int *target, int size, char *filename);
void printArray(int *array, int size);

int main(void)
{
    int size = 0;
    int array_qty = 50;
    char file_tmp[20];
    results *result = malloc(sizeof(results) * 3);


    // =============================================================================
    // Solicita o conjunto de vetores salvos em arquivos
    printf("Qual o tamanho de vetor? ");
    scanf("%i", &size);
    printf("Digite o \"caminho/nome\" dos vetores com esse tamanho: ");
    scanf("%s", &file_tmp);


    // =============================================================================
    // Repete para todos os algoritmos: 
    // Lê todos os vetores de tamanho X e executa o algoritmo em cada um deles
    for (int algo_n = 1; algo_n < 5; algo_n++)
    {
        char filename[strlen(file_tmp) + 6];
        result->comparesum = 0;
        result->sortname = " ";

        for (int i = 0; i < array_qty; i++ ){
            int *array = malloc(sizeof(int) * size);
            sprintf(filename, "%s-%i", file_tmp, i+1);

            readArray(array, size, filename);

            // Executa um algoritmo para cada loop exterior:
            switch (algo_n){
                case 1:
                    result->sortname = "Bubble";
                    result->comparesum += bubbleSort(array, size);
                    break;
                case 2:
                    result->sortname = "Selection";
                    result->comparesum += selectionSort(array, size);
                    break;
                case 3:
                    result->sortname = "Insertion";
                    result->comparesum += insertionSort(array, size);
                    break;
                case 4:
                    result->sortname = "Heap";
                    result->comparesum += heapSort(array, size);
                    break;
                case 5:
                    result->sortname = "Merge";
                    result->comparesum += mergeSort(array, size);
                    break;
                case 6:
                    result->sortname = "Quick";
                    result->comparesum += quickSort(array, size);
                    break;
                case 7:
                    result->sortname = "Count";
                    result->comparesum += countSort(array, size);
                    break;
                case 8:
                    result->sortname = "Bucket";
                    result->comparesum += bucketSort(array, size);
                    break;
                case 9:
                    result->sortname = "Radix";
                    result->comparesum += radixSort(array, size);
                    break;
                default:
                    break;
            }

            if (isSorted(array, size)){
                printf("[%i] Está ordenado\n", i+1);
            } else {
                printf("[%i] Desordenado\n", i+1);
            }

            free(array);
        }

        printf(
            "Soma de comparações %s sort: %li\n", 
            result->sortname,
            result->comparesum
        );
    }

    printf("✅ Todos os vetores[%i] foram processados\n", size);
    free(result);
}


/** Lê um vetor a partir de um arquivo e o armazena no buffer
 * @param target O vetor de destino (deve ter o mesmo tamanho do vetor no arquivo)
 * @param size O tamanho do vetor de destino
*/
int readArray(int *target, int size, char *filename)
{
    FILE *read_p = fopen(filename, "r");

    if (read_p != NULL){
        fread(target, sizeof(int), size, read_p);
        fclose(read_p);
        return 1;
    }

    fclose(read_p);
    free(target);
    return 0;  
}

void printArray(int *array, int size){
    for (int i = 0; i < size; i++){
        printf("%i ", array[i]);
    }
    printf("\n");
}