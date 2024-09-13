#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void preencherVetor(int *vetor, int quantidade);
int* encontrarMenorEndereco(int *vetor, int quantidade);

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

    int *menorEndereco = encontrarMenorEndereco(vetor, quantidade);
    printf("Endereco do menor elemento: %p\n", (void*)menorEndereco);

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

int* encontrarMenorEndereco(int *vetor, int quantidade)
{
    int *menorEndereco = vetor;
    for (int i = 1; i < quantidade; i++)
    {
        if (*(vetor + i) < *menorEndereco)
        {
            menorEndereco = vetor + i;
        }
    }
    return menorEndereco;
}
