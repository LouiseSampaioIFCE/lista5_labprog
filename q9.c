#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarMatrizAleatoria(int **matriz, int tamanho, int limite);
int somaDiagonalPrincipal(int **matriz, int tamanho);

int main()
{
    int tamanho;

    printf("Digite o tamanho da matriz (N x N): ");
    scanf("%d", &tamanho);

    int **matriz = (int**)malloc(tamanho * sizeof(int*));
    if (matriz == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    for (int i = 0; i < tamanho; i++)
    {
        *(matriz + i) = (int*)malloc(tamanho * sizeof(int));
        if (*(matriz + i) == NULL)
        {
            printf("Erro ao alocar memoria.\n");
            exit(1);
        }
    }

    srand(time(NULL));

    gerarMatrizAleatoria(matriz, tamanho, 100); 

    int soma = somaDiagonalPrincipal(matriz, tamanho);

    printf("A soma da diagonal principal e: %d\n", soma);
    if (soma % 2 == 0)
    {
        printf("A soma da diagonal principal e par.\n");
    }
    else
    {
        printf("A soma da diagonal principal e impar.\n");
    }

    for (int i = 0; i < tamanho; i++)
    {
        free(*(matriz + i));
    }
    free(matriz);

    return 0;
}

void gerarMatrizAleatoria(int **matriz, int tamanho, int limite)
{
    for (int i = 0; i < tamanho; i++)
    {
        int *linha = *(matriz + i);
        for (int j = 0; j < tamanho; j++)
        {
            *(linha + j) = rand() % limite; 
        }
    }
}

int somaDiagonalPrincipal(int **matriz, int tamanho)
{
    int soma = 0;
    for (int i = 0; i < tamanho; i++)
    {
        int *linha = *(matriz + i);
        soma += *(linha + i); 
    }
    return soma;
}
