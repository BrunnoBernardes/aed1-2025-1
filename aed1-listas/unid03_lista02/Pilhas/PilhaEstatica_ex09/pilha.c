#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pilha.h"

void inicializaPilha(Pilha* p) {
    if (p == NULL) {
        printf("Erro ao criar a pilha.\n");
        exit(1);
    }

    p->topo = -1;
}

int pilhaVazia(Pilha* p) {
    if (p == NULL) {
        printf("Erro ao criar a pilha.\n");
        exit(1);
    }
    return p->topo == -1;
}

int pilhaCheia(Pilha* p) {
    if (p == NULL) {
        printf("Erro ao criar a pilha.\n");
        exit(1);
    }
    return p->topo == MAX - 1;
}

int empilha(Pilha* p, char c) {
    if (p == NULL) {
        printf("Erro ao criar a pilha.\n");
        exit(1);
    }
    if (pilhaCheia(p)) {
        printf("Pilha cheia.\n");
        return 0;
    }
    p->dados[++(p->topo)] = c;
    return 1;
}

char desempilha(Pilha* p) {
    if (p == NULL) {
        printf("Erro ao criar a pilha.\n");
        exit(1);
    }
    if (pilhaVazia(p)) {
        printf("Pilha vazia.\n");
        return '\0'; // Retorna um caractere nulo se a pilha estiver vazia
    }
    return p->dados[(p->topo)--];
}

int verifica_palindromo(const char* frase) {
    Pilha p;
    if (frase == NULL) {
        printf("Erro ao criar a pilha.\n");
        exit(1);
    }

    inicializaPilha(&p);
    
    char limpa[MAX];
    int j = 0;

    // 1. Limpar a string: letras e números, em minúsculo
    for (int i = 0; frase[i] != '\0'; i++) {
        if (isalnum(frase[i])) {
            char c = tolower(frase[i]);
            limpa[j++] = c;
            empilha(&p, c);
        }
    }

    limpa[j] = '\0';

    // 2. Comparar com o que sai da pilha (inverso)
    for (int i = 0; i < j; i++) {
        if (limpa[i] != desempilha(&p)) {
            return 0;
        }
    }

    return 1;
}