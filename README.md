## APS FMU - Algoritmos
Análise do desempenho de 9 algoritmos de ordenação utilizando o número de comparações executadas como métrica.

### Rodar:
1. Compilação manual com gcc: `gcc main.c sorts.c -o main` -- Necessário para que o `sorts.c` funcione
2. Gere os vetores necessários com o `generate-arrays.c`. Exemplo: 
    - Tamanho: 50
    - Quantidade: 5
    - Nome: "vetor5"
    - Saída: 5 vetores de 50 números inteiros
3. Execute o `main.c`:
    - Insira o tamanho do vetor a ser usado (Exemplo: 50)
    - Insira o nome do vetor criado, **sem o sufixo do número** (Exemplo: vetor50)
    - Escolha um algoritmo para ordenar