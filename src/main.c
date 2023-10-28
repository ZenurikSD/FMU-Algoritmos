#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sorts.h"

int readArray(int *target, int size, char *filename);
void printArray(int *array, int size);

int main(void)
{
    int size = 0;
    int array_qty = 50;
    char file_tmp[20];

    // =============================================================================
    // Solicita o conjunto de vetores salvos em arquivos
    printf("Digite o nome do arquivo que contém o vetor: ");
    scanf("%s", &file_tmp);

    printf("Digite o tamanho do vetor salvo: ");
    scanf("%i", &size);


    // =============================================================================
    // Lê todos os vetores de um tamanho e executa o algoritmo em cada um deles
    char filename[strlen(file_tmp) + 6];
    for (int i = 0; i < array_qty; i++ ){
        int *array = malloc(sizeof(int) * size);
        sprintf(filename, "%s-%i", file_tmp, i+1);

        readArray(array, size, filename);

        bubbleSort(array, size);

        if (isSorted(array, size)){
            printf("[%i] Está ordenado\n", i+1);
        } else {
            printf("[%i] Desordenado\n", i+1);
        }

        free(array);
    }

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
