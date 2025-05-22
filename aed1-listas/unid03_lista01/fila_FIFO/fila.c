#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila {
    int dados[MAX];
    int inicio, fim, qtd;
};

// Função para criar uma fila
Fila* criaFila() {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    
    if (f == NULL) {
        printf("Não foi possível alocar\n");
        exit(1);
    }

    inicializaFila(f);

    return f;
}

void inicializaFila(Fila* f) {
    if (f == NULL) {
        printf("Fila não alocada\n");
        exit(1);
    }
    f->inicio = 0;
    f->fim = 0;
    f->qtd = 0;
}

// Função para liberar a memória da fila
void liberaFila(Fila* f) {
    if (f == NULL) {
        printf("Fila não alocada\n");
        exit(1);
    }
    free(f);
}

// Retorna o tamanho da fila
int tamanhoFila(Fila* f) {
    if (f == NULL) {
        printf("Fila não alocada\n");
        exit(1);
    }
    return f->qtd;
}

// Verifica se a fila esta vazia
int filaVazia(Fila* f) {
    if (f == NULL) {
        printf("Fila não alocada\n");
        exit(1);
    }

    if (f->qtd == 0) {
        printf("Fila vazia!\n");
        return 1;
    }

    return 0;
}

// Verifica se a fila esta cheia
int filaCheia(Fila* f) {
    if (f == NULL) {
        printf("Fila não alocada\n");
        exit(1);
    }

    if (f->qtd == MAX) {
        printf("Fila cheia!\n");
        return 1;
    }
    
    return 0;
}

// Insere um elemento na fila
int insereFila(Fila* f, int elem) {
    if (f == NULL) {
        printf("Fila não alocada\n");
        exit(1);
    }
    
    if (filaCheia(f)) {
        return -1;
    }

    f->dados[f->fim] = elem;
    f->fim++;
    f->qtd++;
    return elem;
}

// Remove um elemento da fila
int removeFila(Fila* f) {
    if (f == NULL) {
        printf("Fila não alocada\n");
        exit(1);
    }
    
    if (filaVazia(f)) {
        return -1;
    }
    
    f->inicio++;;
    f->qtd--;
    return f->dados[f->inicio - 1];
}

// Consulta o primeiro elemento da fila
int consultaFila(Fila* f) {
    if (f == NULL) {
        printf("Fila não alocada\n");
        exit(1);
    }
    
    if (filaVazia(f)) {
        return -1;
    }

    return f->dados[f->inicio];
}

// Imprime os elementos da fila
void imprimeFila(Fila* f) {
    if (f == NULL) {
        printf("Fila não alocada\n");
        exit(1);
    }

    int i = f->inicio;
    int c;
    for (c = 0; c < f->qtd; c++) {
        printf("\t%d\n", f->dados[i]);
        i = (i + 1) % MAX;
    }
}