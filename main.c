#include <stdio.h>
#include <stdlib.h>
#include "sorts.h"

void fillWithRandom(int *array, int size);
void saveArray(int *array, int size, int fileName);


int main(int argc, char *argv)
{
    int *array;
    int size;
    char fileName[200];

    printf("Digite o tamanho do vetor: ");
    scanf("%i", &size);

    printf("Digite o nome do arquivo: ");
    scanf("%s", &fileName);

    array = malloc(sizeof(int) * size);
    fillWithRandom(array, size);
    saveArray(array, size, fileName);



    free(array);
    return 0;
}


/** Preenche um vetor com números inteiros aleatórios
 * @param array Um vetor vazio
 * @param size O tamanho do vetor
 */
void fillWithRandom(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand();
    }
}


/** Salva um vetor para um arquivo */
void saveArray(int *array, int size, int fileName)
{
    FILE *write_p = fopen(fileName, "w");
    if (write_p != NULL){
        fwrite(array, sizeof(int), size, write_p);
        fclose(write_p);
    }
}

/** Lê um vetor a partir de um arquivo e o armazena no buffer
 * @param target O vetor de destino (deve ter o mesmo tamanho do vetor no arquivo)
 * @param size O tamanho do vetor de destino
*/
void readArray(int *target, int size, int fileName)
{
    FILE *read_p = fopen(fileName, "r");
    if (read_p != NULL){
        fread(target, sizeof(int), size, read_p);
        fclose(read_p);
    } else {
        printf("Arquivo não encontrado\n");
        fclose(read_p);
        return 1;
    }
}
