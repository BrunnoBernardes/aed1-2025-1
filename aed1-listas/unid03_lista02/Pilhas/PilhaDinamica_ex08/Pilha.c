#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"

// Funções da pilha
Pilha* criapilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    if (pilha == NULL) {
        printf("Erro de alocação.\n");
        exit(1);
    }
    pilha->topo = NULL;
    return pilha;
}

void liberaPilha(Pilha* pilha) {
    No* temp;
    while (pilha->topo != NULL) {
        temp = pilha->topo;
        pilha->topo = pilha->topo->prox;
        free(temp);
    }
    free(pilha);
}

int tamanhoPilha(Pilha* pilha) {
    int tamanho = 0;
    No* atual = pilha->topo;

    while (atual != NULL) {
        tamanho++;
        atual = atual->prox;
    }

    return tamanho;
}

int pilhaVazia(Pilha* pilha) {
    if (pilha == NULL) {
        printf("Pilha não inicializada.\n");
        exit(1);
    }
    if (pilha->topo == NULL) {
        return 1; // Pilha vazia
    }
    return 0; // Pilha não vazia
}
int inserirPilha(Pilha* pilha, char valor) {
    if (pilha == NULL) {
        printf("Pilha não inicializada.\n");
        exit(1);
    }
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação.\n");
        return 0;
    };
    novo->dado = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    return 1;
}

int removerPilha(Pilha* pilha, char* valor) {
    if (pilha == NULL) {
        printf("Pilha não inicializada.\n");
        return 0;
    }

    if (pilha->topo == NULL) {
        printf("Pilha vazia.\n");
        return 0;
    }

    No* temp = pilha->topo;
    *valor = temp->dado;
    pilha->topo = temp->prox;
    free(temp);

    return 1;
}


// Verifica se a expressão tem parênteses balanceados
int verifica_parentizacao(const char* expr) {
    Pilha* pilha = criapilha();
    char lixo;

    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(') {
            inserirPilha(pilha, '(');
        } else if (expr[i] == ')') {
            if (!removerPilha(pilha, &lixo)) {
                liberaPilha(pilha);
                return 0;
            }
        }
    }

    int resultado = pilhaVazia(pilha);
    liberaPilha(pilha);
    return resultado;
}

