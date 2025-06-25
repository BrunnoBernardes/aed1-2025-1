#include <stdio.h>

#define MAX 100

void verificaOrdenado (int vetor[], int tamanho);

int main() {
    int vetor[MAX] = {1, 2, 4, 5, 6};
    int tamanho = 5;

    verificaOrdenado(vetor, tamanho);
    return 0;
}

void verificaOrdenado (int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho - 1; i++) {
        if (vetor[i] > vetor[i + 1]) {
            printf("NAO ORDENADO\n");
            return;
        }
    }
    printf("ORDENADO\n");
}
// A função tem um laço que percorre o vetor inteiro buscando elementos fora de ordem. O pior caso irá ocorrer se o vetor já estiver previamente ordenado, isto pois a função irá percorrer todo vetor buscando elementos fora de ordem que não existem.
// Portanto, o pior caso é O(n), onde n é o tamanho do vetor.