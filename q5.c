#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherVetor(float *vetor, int quantidade);
float somarElementos(float *vetor, int quantidade);

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

    float *vetor = (float*)malloc(quantidade * sizeof(float));
    if (vetor == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    srand(time(NULL));

    preencherVetor(vetor, quantidade);
    float soma = somarElementos(vetor, quantidade);
    printf("Soma dos elementos: %.2f\n", soma);

    free(vetor);
    return 0;
}

void preencherVetor(float *vetor, int quantidade)
{
    for (int i = 0; i < quantidade; i++)
    {
        *(vetor + i) = (float)(rand() % 100) / 10; 
    }
}

float somarElementos(float *vetor, int quantidade)
{
    float soma = 0;
    for (int i = 0; i < quantidade; i++)
    {
        soma += *(vetor + i);
    }
    return soma;
}
