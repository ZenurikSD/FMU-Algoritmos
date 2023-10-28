#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sorts.h"

int readArray(int *target, int size, char *filename);

int main(void)
{
    int *array;
    int size;
    int array_qty = 1;
    char filename[200];

    printf("Digite o tamanho do vetor: ");
    scanf("%i", &size);

    printf("Digite o nome do arquivo: ");
    scanf("%s", &filename);

    //Seleção do algoritmo
    int option = 1;
    do{
        printf(
            "Escolha um algoritmo de ordenação:\n"
            "  [1] Bubble\n"
            "  [2] Selection\n"
            "  [3] Insertion\n"
            "  [4] Heap\n"
            "  [5] Merge\n"
            "  [6] Quick\n"
            "  [7] Count\n"
            "  [8] Bucket\n"
            "  [9] Radix\n\n"
            "> "
        );
        scanf("%i", &option);
    }
    while(option < 1 && option > 9);


    char new_name[strlen(filename) + 4];
    char append[3];

    // Lê todos os vetores com o nome escolhido, fazendo umas coisas extras pra escolher o arquivo com o sufixo certo
    for (int i = 0; i < array_qty; i++ ){
        array = malloc(sizeof(int) * size);

        sprintf(append, "-%i", i+1);
        strcpy(new_name, filename);
        strcat(new_name, append);

        if (readArray(array, size, filename) != 0)
        {
            free(array);
            return 1;
        }

        free(array);
    }


    //Verifica o tempo antes e depois da execução do algoritmo
    clock_t time_c = clock();

    switch(option){
        case 1: 
            bubbleSort(array, size);
            break;
        case 2: 
            selectionSort();
            break;
        case 3: 
            insertionSort();
            break;
        case 4: 
            heapSort();
            break;
        case 5: 
            mergeSort();
            break;
        case 6: 
            quickSort();
            break;
        case 7: 
            countSort();
            break;
        case 8: 
            bucketSort();
            break;
        case 9: 
            radixSort();
            break;
    }

    float time_sec = (float) (clock() - time_c) / CLOCKS_PER_SEC;
    printf("Tempo gasto: %f segundo(s)\n", time_sec);


    if (isSorted(array, size)){
        printf("Está ordenado\n");
    } else {
        printf("Não está ordenado\n");
    }


    free(array);
    return 0;
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
    } else {
        printf("Arquivo não encontrado\n");
        fclose(read_p);
        return 1;
    }

    return 0;
}
