#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherVetor(int *vetor, int quantidade);
float calcularMedia(int *vetor, int quantidade);
float calcularMediana(int *vetor, int quantidade);
int calcularModa(int *vetor, int quantidade);

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

    srand(time(NULL));

    preencherVetor(vetor, quantidade);

    float media = calcularMedia(vetor, quantidade);
    float mediana = calcularMediana(vetor, quantidade);
    int moda = calcularModa(vetor, quantidade);

    printf("Media: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);
    printf("Moda: %d\n", moda);

    free(vetor);
    return 0;
}

void preencherVetor(int *vetor, int quantidade)
{
    for (int i = 0; i < quantidade; i++)
    {
        *(vetor + i) = rand() % 100; 
    }
}

float calcularMedia(int *vetor, int quantidade)
{
    int soma = 0;
    for (int i = 0; i < quantidade; i++)
    {
        soma += *(vetor + i);
    }
    return (float)soma / quantidade;
}

float calcularMediana(int *vetor, int quantidade)
{
    for (int i = 0; i < quantidade - 1; i++)
    {
        for (int j = i + 1; j < quantidade; j++)
        {
            if (*(vetor + i) > *(vetor + j))
            {
                int temp = *(vetor + i);
                *(vetor + i) = *(vetor + j);
                *(vetor + j) = temp;
            }
        }
    }

    if (quantidade % 2 == 0)
    {
        return ((float)*(vetor + quantidade / 2 - 1) + (float)*(vetor + quantidade / 2)) / 2;
    }
    else
    {
        return *(vetor + quantidade / 2);
    }
}

int calcularModa(int *vetor, int quantidade)
{
    int *contagem = (int*)malloc(100 * sizeof(int)); 
    if (contagem == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    for (int i = 0; i < 100; i++)
    {
        *(contagem + i) = 0;
    }

    for (int i = 0; i < quantidade; i++)
    {
        (*(contagem + *(vetor + i)))++;
    }

    int moda = 0;
    int maxContagem = 0;
    for (int i = 0; i < 100; i++)
    {
        if (*(contagem + i) > maxContagem)
        {
            maxContagem = *(contagem + i);
            moda = i;
        }
    }

    free(contagem);
    return moda;
}
