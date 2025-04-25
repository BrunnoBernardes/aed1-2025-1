#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


// Função para criar uma fila
Fila* criaFila() {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if (f != NULL) {
        f->inicio = 0;
        f->fim = 0;
        f->qtd = 0;
    }
    return f;
}

// Função para liberar a memória da fila
void liberaFila(Fila* f) {
    free(f);
}

// Retorna o tamanho da fila
int tamanhoFila(Fila* f) {
    if (f == NULL) return -1;
    return f->qtd;
}

// Verifica se a fila esta vazia
int filaVazia(Fila* f) {
    if (f == NULL) return -1;
    return (f->qtd == 0) ? 1 : 0;
}

// Verifica se a fila esta cheia
int filaCheia(Fila* f) {
    if (f == NULL) return -1;
    return (f->qtd == MAX) ? 1 : 0;
}

// Insere um elemento na fila
int insereFila(Fila* f, int elem) {
    if (f == NULL || filaCheia(f)) return 0;
    f->dados[f->fim] = elem;
    f->fim = (f->fim + 1) % MAX;
    f->qtd++;
    return 1;
}

// Remove um elemento da fila
int removeFila(Fila* f) {
    if (f == NULL || filaVazia(f)) return 0;
    f->inicio = (f->inicio + 1) % MAX;
    f->qtd--;
    return 1;
}

// Consulta o primeiro elemento da fila
int consultaFila(Fila* f, int* elem) {
    if (f == NULL || filaVazia(f)) return 0;
    *elem = f->dados[f->inicio];
    return 1;
}

// Imprime os elementos da fila
void imprimeFila(Fila* f) {
    if (f == NULL) return;
    printf("Fila: ");
    int i = f->inicio;
    for (int c = 0; c < f->qtd; c++) {
        printf("%d ", f->dados[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}