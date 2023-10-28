#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorts.h"

void fillWithRandom(int *array, int size);
void saveArray(int *array, int size, char *filename);
int readArray(int *target, int size, char *filename);


int main(void)
{
    int *array;
    int size;
    int array_qty = 5;
    char filename[200];

    printf("Digite o tamanho do vetor: ");
    scanf("%i", &size);

    printf("Digite o nome do arquivo: ");
    scanf("%s", &filename);

    // Preenche "n" vetores com valores aleatórios, fazendo umas coisas extras pra ter nomes de arquivos diferentes
    array = malloc(sizeof(int) * size);
    char new_name[strlen(filename) + 4];
    char append[3];
    for (int i = 0; i < array_qty; i++ ){
        fillWithRandom(array, size);

        sprintf(append, "-%i", i+1);
        strcpy(new_name, filename);
        strcat(new_name, append);

        saveArray(array, size, new_name);
    }

    



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
void saveArray(int *array, int size, char *filename)
{
    FILE *write_p = fopen(filename, "w");
    if (write_p != NULL){
        fwrite(array, sizeof(int), size, write_p);
        fclose(write_p);
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
    } else {
        printf("Arquivo não encontrado\n");
        fclose(read_p);
        return 1;
    }
}
