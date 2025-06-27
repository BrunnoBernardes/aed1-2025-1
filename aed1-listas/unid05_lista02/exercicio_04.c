#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int buscaBinariaAproximada(int vetor[], int n, int x)
{
    int inicio = 0;
    int fim = n - 1;
    int meio;
    int melhor = vetor[0];

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;

        if (vetor[meio] == x) return vetor[meio];

        if (abs(vetor[meio] - x) < abs(melhor - x) ||
           (abs(vetor[meio] - x) == abs(melhor - x) && vetor[meio] < melhor)) melhor = vetor[meio];

        if (vetor[meio] < x) inicio = meio + 1;
        else fim = meio - 1;
    }
    return melhor;
}

int main()
{

    int x;
    int vetor[MAX] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    while (scanf("%d", &x)) {
        if (x < 0) break;
        int resultado = buscaBinariaAproximada(vetor, 10, x);
        printf("%d\n", resultado);
    }

    return 0;
}