#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sorts.h"

//Armazena o nome do algoritmo usado e a soma das comparações feitas por ele
typedef struct results{
    char *sortname;
    int timesum;
} results;

int readArray(int *target, int size, char *filename);
void printArray(int *array, int size);

int main(void)
{
    int size = 0;
    int array_qty = 50;
    int sets[] = {5, 10, 50, 100, 1000, 10000};
    int sets_len = 6;
    char file_tmp[20];
    results *result = malloc(sizeof(results) * 3);


    for (int i = 0; i < sets_len; i++)
    {
        size = sets[i];

        // =============================================================================
        // Solicita o conjunto de vetores salvos em arquivos
        printf("Digite o \"caminho/nome\" dos vetores de tamanho %i: ", size);
        scanf("%s", &file_tmp);

        // =============================================================================
        // Prepara o arquivo csv
        FILE *write_p = fopen("RESULTADOS.csv", "a+");
        fputs("Tamanho,Algoritmo,Tempo (seg)\n", write_p);

        // =============================================================================
        // Repete para todos os algoritmos: 
        // Lê todos os vetores de tamanho X e executa o algoritmo em cada um deles
        for (int algo_n = 1; algo_n < 7; algo_n++)
        {
            char filename[strlen(file_tmp) + 6];
            result->timesum = 0;
            result->sortname = " ";

            for (int i = 0; i < array_qty; i++ ){
                int *array = malloc(sizeof(int) * size);
                sprintf(filename, "%s-%i", file_tmp, i+1);

                readArray(array, size, filename);

                //Verifica o tempo antes e depois da execução do algoritmo
                clock_t time_c = clock();

                // Executa um algoritmo para cada loop exterior:
                switch (algo_n){
                    case 1:
                        result->sortname = "Bubble";
                        bubbleSort(array, size);
                        break;
                    case 2:
                        result->sortname = "Selection";
                        selectionSort(array, size);
                        break;
                    case 3:
                        result->sortname = "Insertion";
                        insertionSort(array, size);
                        break;
                    case 4:
                        result->sortname = "Heap";
                        heapSort(array, size);
                        break;
                    case 5:
                        result->sortname = "Merge";
                        mergeSort(array, 0, size - 1);
                        break;
                    case 6:
                        result->sortname = "Quick";
                        quickSort(array, 0, size - 1);
                        break;
                    case 7:
                        result->sortname = "Count";
                        countSort(array, size);
                        break;
                    case 8:
                        result->sortname = "Bucket";
                        bucketSort(array, size);
                        break;
                    case 9:
                        result->sortname = "Radix";
                        radixSort(array, size);
                        break;
                    default:
                        break;
                }
                result->timesum += (clock() - time_c);

                if (isSorted(array, size)){
                    printf("[%i] Está ordenado\n", i+1);
                } else {
                    printf("[%i] Desordenado\n", i+1);
                }

                free(array);

            }
            double time_avg = (double) result->timesum / CLOCKS_PER_SEC;
            printf("%s sort executado em %lf segundo(s)\n", result->sortname, time_avg);

            // Salva o resultado no arquivo csv
            fprintf(write_p, "%i,%s,%lf\n", size, result->sortname, time_avg);
        }

        fputs("\n", write_p);

        printf("✅ Todos os vetores[%i] foram processados\n", size);
        fclose(write_p);
    }

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