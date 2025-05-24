#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fila.h"

Fila* criaFila() {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if (f == NULL) {
        printf("Erro ao alocar memoria para a fila!\n");
        exit(1);
    }

    inicializaFila(f);

    return f;
}

void inicializaFila(Fila* f) {
    if (f == NULL) {
        printf("Erro ao alocar memoria para a fila!\n");
        exit(1);
    }

    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}

void liberaFila(Fila* f) {
    if (f == NULL) {
        printf("Erro ao alocar memoria para a fila!\n");
        exit(1);
    }

    No* atual = f->inicio;
    No* proximo;
    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    free(f);
}

int insereFila(Fila* f, Cliente c) {
    if (f == NULL) {
        printf("Erro ao alocar memoria para a fila!\n");
        exit(1);
    }

    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memoria para a cliente!\n");
        return -1;
    }

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

int removeFila(Fila* f, Cliente* c) {
    if (f == NULL) {
        printf("Erro ao alocar memoria para a fila!\n");
        exit(1);
    }
    
    if (f->inicio == NULL) {
        printf("Fila vazia!\n");
        return 0;
    }

    No* aux = f->inicio;
    *c = aux->dados;
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(aux);
    f->tamanho--;
    return 1;
}

void listarFila(Fila* f) {
    if (f == NULL) {
        printf("Erro ao alocar memoria para a fila!\n");
        exit(1);
    }
    
    if (f->inicio == NULL) {
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
    if (f == NULL) {
        printf("Erro ao alocar memoria para a fila!\n");
        exit(1);
    }
    
    return f->tamanho;
}

float tempoMedioEspera(Fila* f) {
    if (f == NULL) {
        printf("Erro ao alocar memoria para a fila!\n");
        exit(1);
    }
    return f->tamanho * 10.0; // 10 minutos por cliente
}
