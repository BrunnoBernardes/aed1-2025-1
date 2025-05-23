#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fila.h"

Fila* criaFila() {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
        f->tamanho = 0;
    }
    return f;
}

void liberaFila(Fila* f) {
    if (f != NULL) {
        No* atual;
        while (f->inicio != NULL) {
            atual = f->inicio;
            f->inicio = f->inicio->prox;
            free(atual);
        }
        free(f);
    }
}

int enfileira(Fila* f, Cliente c) {
    if (f == NULL) return 0;

    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return 0;

    novo->dados = c;
    novo->prox = NULL;

    if (f->fim == NULL) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }

    f->fim = novo;
    f->tamanho++;
    return 1;
}

int desenfileira(Fila* f, Cliente* c) {
    if (f == NULL || f->inicio == NULL) return 0;

    No* aux = f->inicio;
    *c = aux->dados;
    f->inicio = f->inicio->prox;

    if (f->inicio == NULL)
        f->fim = NULL;

    free(aux);
    f->tamanho--;
    return 1;
}

void listarFila(Fila* f) {
    if (f == NULL || f->inicio == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    No* atual = f->inicio;
    while (atual != NULL) {
        printf("Codigo: %d - Nome: %s\n", atual->dados.codigo, atual->dados.nome);
        atual = atual->prox;
    }
}

int tamanhoFila(Fila* f) {
    if (f == NULL) return 0;
    return f->tamanho;
}

float tempoMedioEspera(Fila* f) {
    if (f == NULL) return 0;
    return f->tamanho * 10.0; // 10 minutos por cliente
}
