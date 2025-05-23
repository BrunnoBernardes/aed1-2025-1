#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

// Definição da estrutura da fila
struct fila {
    int inicio;
    int fim;
    int qtd;
    int dados[MAX];
};

// Função para criar uma fila
Fila* cria_Fila() {
    Fila* fi = (Fila*)malloc(sizeof(Fila));
    if (fi == NULL) {
        printf("Erro ao alocar memoria para a fila.\n");
        exit(1);
    }

    inicializa_Fila(fi);

    return fi;
}

// Função para inicializar a fila
void inicializa_Fila(Fila* fi) {
    if (fi == NULL) {
        printf("Erro ao alocar memoria para a fila.\n");
        exit(1);
    }

    fi->inicio = 0;
    fi->fim = 0;
    fi->qtd = 0;
}

// Função para liberar a memória da fila
void libera_Fila(Fila* fi) {
    free(fi);
}

int insere_Fila(Fila* fi, int elemento) {
    if (fi == NULL) {
        printf("Fila não inicializada.\n");
        exit(1);
    }

    if (fi->qtd == MAX) {
        printf("Fila cheia.\n");
        return 0;
    }

    fi->dados[fi->fim] = elemento;
    fi->fim++;
    fi->qtd++;

    return 1;
}

int remove_Fila(Fila* fi) {
    if (fi == NULL) {
        printf("Fila não inicializada.\n");
        exit(1);
    }

    if (fi->qtd == 0) {
        printf("Fila vazia.\n");
        return 0;
    }

    fi->inicio++;
    fi->qtd--;

    return 1;
}

int copia_Fila(Fila* fi, Fila* fi2) {
    if (fi == NULL || fi2 == NULL) {
        printf("Fila não inicializada.\n");
        exit(1);
    }

    if (fi->qtd == 0) {
        printf("Fila vazia.\n");
        return 0;
    }

    for (int i = fi->inicio; i < fi->fim; i++) {
        insere_Fila(fi2, fi->dados[i]);
    }

    return 1;
}

void imprime_Fila(Fila* fi) {
    if (fi == NULL) {
        printf("Fila não inicializada.\n");
        exit(1);
    }

    if (fi->qtd == 0) {
        printf("Fila vazia.\n");
        return;
    }

    for (int i = fi->inicio; i < fi->fim; i++) {
        printf("%d ", fi->dados[i]);
    }
    printf("\n");
}

int intercala_Filas(Fila* fi, Fila* fi2, Fila* fi3) {
    if (fi == NULL || fi2 == NULL || fi3 == NULL) {
        printf("Fila nao inicializada.\n");
        exit(1);
    }

    if (fi->qtd == 0 && fi2->qtd == 0) {
        printf("Ambas as filas estao vazias.\n");
        return 0;
    }

    while (fi->qtd > 0 || fi2->qtd > 0) {
        if (fi->qtd > 0) {
            insere_Fila(fi3, fi->dados[fi->inicio]);
            remove_Fila(fi);
        }
        if (fi2->qtd > 0) {
            insere_Fila(fi3, fi2->dados[fi2->inicio]);
            remove_Fila(fi2);
        }
    }

    return 1;
}

