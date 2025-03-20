#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int N;

    do {
        printf("Digite um valor inteiro positivo para N: ");
        scanf("%d", &N);
        if (N <= 0) {
            printf("Valor invalido! N deve ser um numero positivo.\n");
        }
    } while (N <= 0); // loop enquanto N for inválido

    int *V = (int *)malloc(N * sizeof(int));
    if (V == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    printf("Digite os %d elementos do vetor (digite um valor maior ou igual a 2):\n", N);
    for (int i = 0; i < N; i++) {
        do {
            printf("Elemento %d: ", i + 1);
            scanf("%d", &V[i]);
            if (V[i] < 2) {
                printf("Valor invalido! Digite um numero maior ou igual a 2.\n");
            }
        } while (V[i] < 2); // loop enquanto o valor for inválido
    }

    printf("Vetor lido: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", V[i]);
    }

    printf("\n");
    free(V);

    return 0;
}