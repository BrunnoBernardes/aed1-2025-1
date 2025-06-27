// Exercício feito sem TAD, apenas com ponteiros e alocação dinâmica de memória.

#include   <stdio.h>
#include   <stdlib.h>
#include   <string.h>

int insertionCount(int *vetor, int n) {
    int trocas = 0;
    for (int i = 1; i < n; i++) {
        int chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
            trocas++;
        }
        vetor[j + 1] = chave;
    }
    printf("Insertion Sort Trocas: %d\n", trocas);
    return trocas;
}

int selectionCount(int *vetor, int n) {
    int trocas = 0;
    for (int i = 0; i < n - 1; i++) {
        int index = i;
        for (int j = i + 1; j < n; j++) {
            if (vetor[j] < vetor[index]) {
                index = j;
            }
        }
        if (index != i) {
            int temp = vetor[i];
            vetor[i] = vetor[index];
            vetor[index] = temp;
            trocas++;
        }
    }
    printf("Selection Sort Trocas: %d\n", trocas);
    return trocas;
}

int main () {

    int n;
    scanf("%d", &n);
    if (n < 1 || n > 1000) return 0;

    int *vetor_principal = (int *)malloc(n * sizeof(int));
    int *vetor_auxiliar1 = (int *)malloc(n * sizeof(int));
    int *vetor_auxiliar2 = (int *)malloc(n * sizeof(int));
    if (vetor_principal == NULL || vetor_auxiliar1 == NULL || vetor_auxiliar2 == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor_principal[i]);
        vetor_auxiliar1[i] = vetor_principal[i];
        vetor_auxiliar2[i] = vetor_principal[i];
    }

    int trocasInsertion = insertionCount(vetor_auxiliar1, n);
    int trocasSelection = selectionCount(vetor_auxiliar2, n);

    printf("%d\n", trocasInsertion - trocasSelection); // Resultado diferente da saida esperada...

    free(vetor_principal);
    free(vetor_auxiliar1);
    free(vetor_auxiliar2);

    return 0;
}