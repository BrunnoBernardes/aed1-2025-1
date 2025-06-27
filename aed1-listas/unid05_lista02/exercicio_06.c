#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int tamanho;
    int capacidade;
} Lista;

Lista *criaLista(int capacidade) {
    Lista *l = (Lista *)malloc(sizeof(Lista));
    if (l == NULL){
        printf("Erro ao alocar memoria para a lista.\n");
        exit(1);
    }
    l->dados = (int *)malloc(capacidade * sizeof(int));
    l->tamanho = 0;
    l->capacidade = capacidade;
    return l;
}

void liberaLista(Lista *l) {
    if (l != NULL) {
        free(l->dados);
        free(l);
    }
}

void insereLista(Lista *l, int valor) {
    if (l->tamanho < l->capacidade) {
        l->dados[l->tamanho] = valor;
        l->tamanho++;
    }
    else {
        printf("Lista cheia.\n");
    }
}

void selectionSortCrescente(Lista *l) {
    for (int i = 0; i < l->tamanho - 1; i++) {
        int index = i;
        for (int j = i + 1; j < l->tamanho; j++) {
            if (l->dados[j] < l->dados[index]) {
                index = j;
            }
        }
        if (index != i) {
            int temp = l->dados[i];
            l->dados[i] = l->dados[index];
            l->dados[index] = temp;
        }
    }
}

void selectionSortDecrescente(Lista *l) {
    for (int i = 0; i < l->tamanho - 1; i++) {
        int index = i;
        for (int j = i + 1; j < l->tamanho; j++) {
            if (l->dados[j] > l->dados[index]) {
                index = j;
            }
        }
        if (index != i) {
            int temp = l->dados[i];
            l->dados[i] = l->dados[index];
            l->dados[index] = temp;
        }
    }
}

void imprimeLista(Lista *l) {
    for (int i = 0; i < l->tamanho; i++) {
        printf("%d", l->dados[i]);
        if (i < l->tamanho - 1) printf(" ");
    }
    printf("\n");
}

int main () {
    int n;
    scanf("%d", &n);
    if (n < 1 || n > 100) return 0;

    Lista *pares = criaLista(n);
    Lista *impares = criaLista(n);

    for (int i = 0; i < n; i++) {
        int valor;
        scanf("%d", &valor);
        if (valor % 2 == 0) {
            insereLista(pares, valor);
        } else {
            insereLista(impares, valor);
        }
    }

    selectionSortCrescente(pares);
    selectionSortDecrescente(impares);

    if (pares->tamanho > 0) imprimeLista(pares);
    if (impares->tamanho > 0) imprimeLista(impares);

    liberaLista(pares);
    liberaLista(impares);

    return 0;
}