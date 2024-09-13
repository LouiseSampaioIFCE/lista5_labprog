#include <stdio.h>
#include <stdlib.h>

int encontrarMinimo(int *vetor, int quantidade);
int encontrarMaximo(int *vetor, int quantidade);
void normalizarVetor(int *vetor, float *vetorNormalizado, int quantidade, int minimo, int maximo);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Use: %s <quantidade_de_elementos>\n", argv[0]);
        exit(1);
    }

    int quantidade = atoi(argv[1]);
    if (quantidade <= 0)
    {
        printf("Quantidade deve ser um numero positivo.\n");
        exit(1);
    }

    int *vetor = (int*)malloc(quantidade * sizeof(int));
    if (vetor == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    float *vetorNormalizado = (float*)malloc(quantidade * sizeof(float));
    if (vetorNormalizado == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        free(vetor);
        exit(1);
    }

    printf("Digite %d elementos:\n", quantidade);
    for (int i = 0; i < quantidade; i++)
    {
        scanf("%d", (vetor + i));
    }

    int minimo = encontrarMinimo(vetor, quantidade);
    int maximo = encontrarMaximo(vetor, quantidade);

    if (minimo == maximo)
    {
        printf("Todos os elementos do vetor sao iguais. Normalizacao nao e possivel.\n");
        free(vetor);
        free(vetorNormalizado);
        exit(1);
    }

    normalizarVetor(vetor, vetorNormalizado, quantidade, minimo, maximo);

    printf("Vetor normalizado:\n");
    for (int i = 0; i < quantidade; i++)
    {
        printf("%.2f ", *(vetorNormalizado + i));
    }
    printf("\n");

    free(vetor);
    free(vetorNormalizado);
    return 0;
}

int encontrarMinimo(int *vetor, int quantidade)
{
    int minimo = *vetor;
    for (int i = 1; i < quantidade; i++)
    {
        if (*(vetor + i) < minimo)
        {
            minimo = *(vetor + i);
        }
    }
    return minimo;
}

int encontrarMaximo(int *vetor, int quantidade)
{
    int maximo = *vetor;
    for (int i = 1; i < quantidade; i++)
    {
        if (*(vetor + i) > maximo)
        {
            maximo = *(vetor + i);
        }
    }
    return maximo;
}

void normalizarVetor(int *vetor, float *vetorNormalizado, int quantidade, int minimo, int maximo)
{
    for (int i = 0; i < quantidade; i++)
    {
        *(vetorNormalizado + i) = ((float)*(vetor + i) - minimo) / (maximo - minimo);
    }
}
