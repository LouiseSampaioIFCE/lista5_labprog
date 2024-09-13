#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarVetorAleatorio(int *vetor, int tamanho, int limite);
void gerarMatrizCoocorrencias(int *vetorX, int *vetorY, int **matriz, int tamanho);
void imprimirMatriz(int **matriz, int tamanho);

int main()
{
    int tamanho;

    printf("Digite o tamanho dos vetores e da matriz (N x N): ");
    scanf("%d", &tamanho);

    int *vetorX = (int*)malloc(tamanho * sizeof(int));
    int *vetorY = (int*)malloc(tamanho * sizeof(int));
    if (vetorX == NULL || vetorY == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    int **matrizM = (int**)malloc(tamanho * sizeof(int*));
    if (matrizM == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    for (int i = 0; i < tamanho; i++)
    {
        *(matrizM + i) = (int*)malloc(tamanho * sizeof(int));
        if (*(matrizM + i) == NULL)
        {
            printf("Erro ao alocar memoria.\n");
            exit(1);
        }
    }

    srand(time(NULL));

    gerarVetorAleatorio(vetorX, tamanho, tamanho);
    gerarVetorAleatorio(vetorY, tamanho, tamanho);
    gerarMatrizCoocorrencias(vetorX, vetorY, matrizM, tamanho);

    printf("Matriz de coocorrencias:\n");
    imprimirMatriz(matrizM, tamanho);

    free(vetorX);
    free(vetorY);
    for (int i = 0; i < tamanho; i++)
    {
        free(*(matrizM + i));
    }
    free(matrizM);

    return 0;
}

void gerarVetorAleatorio(int *vetor, int tamanho, int limite)
{
    for (int i = 0; i < tamanho; i++)
    {
        *(vetor + i) = rand() % limite;
    }
}

void gerarMatrizCoocorrencias(int *vetorX, int *vetorY, int **matriz, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        int x = *(vetorX + i);
        int y = *(vetorY + i);
        if (x < tamanho && y < tamanho)
        {
            int *linha = *(matriz + x);
            *(linha + y) += 1;
        }
    }
}

void imprimirMatriz(int **matriz, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        int *linha = *(matriz + i);
        for (int j = 0; j < tamanho; j++)
        {
            printf("%d ", *(linha + j));
        }
        printf("\n");
    }
}
