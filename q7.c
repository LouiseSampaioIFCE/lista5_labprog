#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void preencherVetor(float *vetor, int quantidade);
float calcularErroMedioQuadratico(float *vetorA, float *vetorB, int quantidade);

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

    float *vetorA = (float*)malloc(quantidade * sizeof(float));
    float *vetorB = (float*)malloc(quantidade * sizeof(float));
    if (vetorA == NULL || vetorB == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    srand(time(NULL));

    preencherVetor(vetorA, quantidade);
    preencherVetor(vetorB, quantidade);

    float erroMedioQuadratico = calcularErroMedioQuadratico(vetorA, vetorB, quantidade);
    printf("Erro medio quadratico: %.2f\n", erroMedioQuadratico);

    free(vetorA);
    free(vetorB);
    return 0;
}

void preencherVetor(float *vetor, int quantidade)
{
    for (int i = 0; i < quantidade; i++)
    {
        *(vetor + i) = (float)(rand() % 100) / 10; 
    }
}

float calcularErroMedioQuadratico(float *vetorA, float *vetorB, int quantidade)
{
    float somaQuadrados = 0;
    for (int i = 0; i < quantidade; i++)
    {
        float diff = *(vetorA + i) - *(vetorB + i);
        somaQuadrados += diff * diff;
    }
    return sqrt(somaQuadrados / quantidade);
}
