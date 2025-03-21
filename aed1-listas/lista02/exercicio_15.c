#include <stdio.h>
#include <stdlib.h>

int main (){

    int N, valor;
    int i, j;

    printf("Digite o numero de linhas da matriz triangular (cuidado com valores muito grandes): "); // Por ser uma matriz que dobra o primeiro elemento, valores muito grandes podem causar overflow!
    scanf ("%d", &N);

    int **matriz = (int **)malloc(N * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro ao alocar memoria em linhas!\n");
        return 1;
    }

    for (i = 0; i < N; i++) {
        matriz[i] = (int *)malloc(N * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memoria em colunas!\n");
            return 1;
        }
    }

    printf("Digite o primeiro elemento da matriz triangular: ");
    scanf("%d", &matriz[0][0]);
    valor = matriz[0][0];

    for (i = 1; i < N; i++) {
        valor *= 2;
        matriz[i][0] = valor;
        for (j = 1; j <= i; j++) {
            valor *= 2;
            matriz[i][j] = valor;
        }
    }

    printf("\nMatriz triangular:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (j <= i) {
                printf("%4d ", matriz[i][j]);
            } else {
                printf("%4d ", 0);
            }
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
    
    