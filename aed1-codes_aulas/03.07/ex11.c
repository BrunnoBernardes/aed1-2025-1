#include <stdio.h>
#include <stdlib.h>

int main () {

    int tamanho_matriz, linha, coluna;
    printf("Digite o tamanho da matriz triangular: ");
    scanf("%d", &tamanho_matriz);

    int *matriz = (int *) malloc(tamanho_matriz * (tamanho_matriz + 1) / 2 * sizeof(int)); // N(N+1)/2 fórmula para matriz triangular
    if (matriz == NULL) {
        printf("Memoria insuficiente!\n");
        return 1;
    }

    int *matriz_quintuplicada = (int *) malloc(tamanho_matriz * (tamanho_matriz + 1) / 2 * sizeof(int));
    if (matriz_quintuplicada == NULL) {
        printf("Memoria insuficiente!\n");
        return 1;
    }

    printf("\n");

    for (linha = 0; linha < tamanho_matriz; linha++) {
        for (coluna = 0; coluna < linha + 1; coluna++) {
            printf("Digite o valor da posicao %d %d: ", linha, coluna);
            scanf("%d", &matriz[linha * (linha + 1) / 2 + coluna]);
            matriz_quintuplicada[linha * (linha + 1) / 2 + coluna] = matriz[linha * (linha + 1) / 2 + coluna] * 5;
        }
    }

    printf("\n");

    for (linha = 0; linha < tamanho_matriz; linha++) {
        for (coluna = 0; coluna < linha + 1; coluna++) {
            printf("%d ", matriz[linha * (linha + 1) / 2 + coluna]);
        }
        printf("\n");
    }

    printf("\n");

    for (linha = 0; linha < tamanho_matriz; linha++) {
        for (coluna = 0; coluna < linha + 1; coluna++) {
            printf("%d ", matriz_quintuplicada[linha * (linha + 1) / 2 + coluna]);
        }
        printf("\n");
    }

    free(matriz);
    free(matriz_quintuplicada);

    return 0;
}