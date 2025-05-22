#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

struct fila_prioridade {
    Elemento elemento[MAX];
    int qtd;
};

// Cria uma fila de prioridade
FilaPrio* criaFila() {
    FilaPrio* f = (FilaPrio*)malloc(sizeof(FilaPrio));
    if (f == NULL) {
        printf("Erro ao alocar memoria para a fila.\n");
        exit(1);
    }

    inicializaFila(f);

    return f;
}

// Inicializa a fila de prioridade
void inicializaFila(FilaPrio* f) {
    f->qtd = 0;
}

// Libera a memória da fila de prioridade
void liberaFila(FilaPrio* f) {
    free(f);
}

// Retorna o tamanho da fila de prioridade
int tamanhoFila(FilaPrio* f) {
    if (f == NULL) {
        printf("Fila não inicializada.\n");
        exit(1);
    }

    return f->qtd;
}

// Verifica se a fila de prioridade está vazia
int filaVazia(FilaPrio* f) {
    if (f == NULL) {
        printf("Fila não inicializada.\n");
        exit(1);
    }

    if (f->qtd == 0) {
        printf("Fila vazia.\n");
        return 1;
    }
    return 0;
}

// Verifica se a fila de prioridade está cheia
int filaCheia(FilaPrio* f) {
    if (f == NULL) {
        printf("Fila não inicializada.\n");
        exit(1);
    }

    if (f->qtd == MAX) {
        printf("Fila cheia.\n");
        return 1;
    }
    return 0;
}

// Insere um elemento na fila de prioridade
int insereFila(FilaPrio* f, Elemento elem) {
    if (f == NULL) {
        printf("Fila não inicializada.\n");
        exit(1);
    }

    if (filaCheia(f)) {
        return -1;
    }

    int i = f->qtd - 1;
    // Move os elementos para a direita até encontrar a posição correta
    while (i >= 0 && f->elemento[i].prioridade > elem.prioridade) {
        f->elemento[i + 1] = f->elemento[i];
        i--;
    }
    f->elemento[i + 1] = elem;
    f->qtd++;
    return 0;
}

// Remove o elemento de maior prioridade da fila de prioridade
int removeFila(FilaPrio* f) {
    if (f == NULL) {
        printf("Fila não inicializada.\n");
        exit(1);
    }

    if (filaVazia(f)) {
        return -1;
    }

    f->qtd--;
    return 0;
}

// Consulta o elemento de maior prioridade da fila de prioridade
int consultaFila(FilaPrio* f, Elemento* elem) {
    if (f == NULL) {
        printf("Fila não inicializada.\n");
        exit(1);
    }

    if (filaVazia(f)) {
        return -1;
    }

    *elem = f->elemento[f->qtd - 1]; // O elemento de maior prioridade está no final da fila
    return 0;
}

// Imprime os elementos da fila de prioridade
void imprimeFila(FilaPrio* f) {
    if (f == NULL) {
        printf("Fila não inicializada.\n");
        exit(1);
    }

    if (filaVazia(f)) {
        return;
    }

    for (int i = 0; i < f->qtd; i++) {
        printf("\tPrioridade: %d, Elemento: %d\n", f->elemento[i].prioridade, f->elemento[i].dado);
    }
}