#include <stdio.h>
#include <stdlib.h>

void realizarOperacao(int valor1, int valor2, char operacao);

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Use: %s <valor1> <valor2> <operacao>\n", argv[0]);
        exit(1);
    }

    int valor1 = atoi(argv[1]);
    int valor2 = atoi(argv[2]);
    char operacao = argv[3][0];

    realizarOperacao(valor1, valor2, operacao);

    return 0;
}

void realizarOperacao(int valor1, int valor2, char operacao)
{
    int resultado;

    switch (operacao)
    {
        case '+':
            resultado = valor1 + valor2;
            printf("Resultado da soma: %d\n", resultado);
            break;
        case '*':
            resultado = valor1 * valor2;
            printf("Resultado da multiplicacao: %d\n", resultado);
            break;
        default:
            printf("Operacao invalida.\n");
            break;
    }
}
