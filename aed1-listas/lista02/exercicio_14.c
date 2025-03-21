#include <stdio.h>
#include <stdlib.h>

int main (){

    int N;
    int i, j;

    printf("Digite a dimensao da matriz quadrada: ");
    scanf("%d", &N);

    int **matriz = (int **)malloc(N * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro ao alocar memória em linhas!\n");
        return 1;
    }

    for (i = 0; i < N; i++) {
        matriz[i] = (int *)malloc(N * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memória em colunas!\n");
            return 1;
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i == j) {
                matriz[i][j] = 0;
            } else if (i < j) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = -1;
            }
        }
    }

    printf("\nMatriz resultante:\n");
    for (i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Liberação da memória alocada
    for (i = 0; i < N; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}