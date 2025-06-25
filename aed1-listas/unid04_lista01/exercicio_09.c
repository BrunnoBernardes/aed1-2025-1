#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool buscaBinaria(int vetor[], int tamanho, int valor);

int main() {
    int vetor[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tamanho = 10;
    int valor = 5;

    if (buscaBinaria(vetor, tamanho, valor)) {
        printf("Valor encontrado.\n");
    } else {
        printf("Valor nao encontrado.\n");
    }

    return 0;
}

bool buscaBinaria(int vetor[], int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (vetor[meio] == valor) {
            return true;
        } else if (vetor[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return false;
}

// O pior caso ocorre quando o valor não está presente no vetor ou está localizado na extremidade, fazendo com que o algoritmo percorra todo o vetor. Portanto, a complexidade de tempo no pior caso é O(log n), onde n é o tamanho do vetor. Isso se deve ao fato de que a cada iteração o tamanho da parte do vetor a ser pesquisada é reduzido pela metade.