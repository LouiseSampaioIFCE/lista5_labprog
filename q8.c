#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarMatrizAleatoria(int **matriz, int linhas, int colunas, int limite);
void binarizarMatriz(int **matriz, int **matrizBinarizada, int linhas, int colunas, int limiar);
void imprimirMatriz(int **matriz, int linhas, int colunas);
void liberarMatriz(int **matriz, int linhas);

int main()
{
    int linhas, colunas, limiar;

    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &linhas);

    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &colunas);

    printf("Digite o limiar para binarizacao: ");
    scanf("%d", &limiar);

    int **matrizM = (int**)malloc(linhas * sizeof(int*));
    int **matrizS = (int**)malloc(linhas * sizeof(int*));

    if (matrizM == NULL || matrizS == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    for (int i = 0; i < linhas; i++)
    {
        *(matrizM + i) = (int*)malloc(colunas * sizeof(int));
        *(matrizS + i) = (int*)malloc(colunas * sizeof(int));

        if (*(matrizM + i) == NULL || *(matrizS + i) == NULL)
        {
            printf("Erro ao alocar memoria.\n");
            exit(1);
        }
    }

    srand(time(NULL));

    gerarMatrizAleatoria(matrizM, linhas, colunas, 100); 
    printf("Matriz M gerada:\n");
    imprimirMatriz(matrizM, linhas, colunas);

    binarizarMatriz(matrizM, matrizS, linhas, colunas, limiar);
    printf("Matriz S binarizada:\n");
    imprimirMatriz(matrizS, linhas, colunas);

    liberarMatriz(matrizM, linhas);
    liberarMatriz(matrizS, linhas);

    return 0;
}

void gerarMatrizAleatoria(int **matriz, int linhas, int colunas, int limite)
{
    for (int i = 0; i < linhas; i++)
    {
        int *linha = *(matriz + i);
        for (int j = 0; j < colunas; j++)
        {
            *(linha + j) = rand() % limite; 
        }
    }
}

void binarizarMatriz(int **matriz, int **matrizBinarizada, int linhas, int colunas, int limiar)
{
    for (int i = 0; i < linhas; i++)
    {
        int *linhaM = *(matriz + i);
        int *linhaS = *(matrizBinarizada + i);
        for (int j = 0; j < colunas; j++)
        {
            *(linhaS + j) = (*(linhaM + j) > limiar) ? 1 : 0;
        }
    }
}

void imprimirMatriz(int **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        int *linha = *(matriz + i);
        for (int j = 0; j < colunas; j++)
        {
            printf("%d ", *(linha + j));
        }
        printf("\n");
    }
}

void liberarMatriz(int **matriz, int linhas)
{
    for (int i = 0; i < linhas; i++)
    {
        free(*(matriz + i));
    }
    free(matriz);
}
