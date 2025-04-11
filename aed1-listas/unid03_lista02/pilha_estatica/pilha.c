#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct pilha {
    int quantidade;
    int elementos[MAX];
};

Pilha* cria_Pilha() {
    Pilha *pi;
    pi = (Pilha*) malloc(sizeof(Pilha));
    if (pi == NULL) {
        printf("Erro na alocacao de memoria");
        // return NULL;
        // exit (1);
        // return 1;
        return -1;
    }
    return pi;
}