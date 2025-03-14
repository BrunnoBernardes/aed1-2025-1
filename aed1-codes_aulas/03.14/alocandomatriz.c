#include <stdio.h>
#include <stdlib.h>

int main (){

    int **p; //2 "*" = 2 niveis = 2 dimensoes
    int i, j, N = 2;
    p = (int **) malloc(N * sizeof(int *));
    if (p == NULL) {
        printf("Erro de alocação de memória\n");
        return 1;
    }
    for (i = 0; i < N; i++) {
        p[i] = (int *) malloc(N * sizeof(int));
        if (p[i] == NULL) {
            printf("Erro de alocação de memória\n");
            return 1;
        }
        for (j = 0; j < N; j++) {
            scanf("%d", &p[i][j]);
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < N; i++) {
        free(p[i]);
    }
    free(p);

    return 0;
}