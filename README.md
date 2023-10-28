## APS FMU - Algoritmos
Análise do desempenho de 9 algoritmos de ordenação utilizando o número de comparações executadas como métrica.

### Rodar:
1. Compilação manual com gcc: `gcc main.c sorts.c -o main` -- Necessário para que o `sorts.c` funcione
2. Gere os vetores necessários com o `generate-arrays.c`. Exemplo: 
    - Tamanho: 5
    - Caminho: "vetores/vetor5"
    - Saída: 50 vetores de 5 números inteiros
3. Execute o `main.c`:
    - Insira o nome do vetor criado, **sem o sufixo do número no arquivo** (Exemplo: "vetor50" e não "vetor50-1")