#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fillWithRandom(int *array, int size);
int saveArray(int *array, int size, char *filename);

int main(void)
{
    int *array;
    int size;
    int array_qty;
    char filename[200];

    printf("Digite o tamanho do vetor a ser gerado: ");
    scanf("%i", &size);

    do{
        printf("Quantos vetores? ");
        scanf("%i", &array_qty);
    }
    while(array_qty < 1 || array_qty > 100);

    printf("Digite o nome do arquivo: ");
    scanf("%s", &filename);


    // Preenche "n" vetores com valores aleatórios, fazendo umas coisas extras pra ter nomes de arquivos diferentes
    char new_name[strlen(filename) + 4];
    char append[10];

    for (int i = 0; i < array_qty; i++ ){
        array = malloc(sizeof(int) * size);
        fillWithRandom(array, size);

        sprintf(append, "-%i.dat", i+1);
        strcpy(new_name, filename);
        strcat(new_name, append);

        if (saveArray(array, size, new_name) != 0){
            free(array);
            return 1;
        };

        free(array);
    }

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
int saveArray(int *array, int size, char *filename)
{
    FILE *write_p = fopen(filename, "w");
    if (write_p != NULL){
        fwrite(array, sizeof(int), size, write_p);
        fclose(write_p);
        return 0;
    }
    printf("Erro ao gravar o arquivo");
    return 1;
}