#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Definição da estrutura da pilha
struct pilha {
    int index;
    int elem[TAM];
};

// Cria uma nova pilha
Pilha *cria_pilha() {
    Pilha *pilha = malloc(sizeof(Pilha));

    if (pilha == NULL) {
        printf("Não foi possível alocar\n");
        exit(1);
    }

    inicializa_pilha(pilha);

    return pilha;
}

// Inicializa a pilha
void inicializa_pilha(Pilha *pilha) {
    if (pilha == NULL) {
        printf("Pilha não alocada\n");
        exit(1);
    }
    pilha->index = 0;
}

// Verifica o tamanho da pilha
int tamanho_pilha(Pilha *pilha) {
    if (pilha == NULL) {
        printf("Pilha não alocada\n");
        exit(1);
    }
    return pilha->index;
}

// Verifica se a pilha está cheia
int pilha_cheia(Pilha *pilha) {
    if (pilha == NULL) {
        printf("Pilha não alocada\n");
        exit(1);
    }

    if (pilha->index == TAM) {
        printf("Pilha cheia!\n");
        return 1;
    }

    return 0;
}

// Verifica se a pilha está vazia
int pilha_vazia(Pilha *pilha) {
    if (pilha == NULL) {
        printf("Pilha não alocada\n");
        exit(1);
    }

    if (pilha->index == 0) {
        printf("Pilha vazia!\n");
        return 1;
    }

    return 0;
}

// Insere um elemento na pilha (empilha)
void insere_pilha(Pilha *pilha, int elem) {
    if (pilha == NULL) {
        printf("Pilha não alocada\n");
        exit(1);
    }

    if (pilha_cheia(pilha)) {
        return;
    }

    pilha->elem[pilha->index] = elem;
    pilha->index++;
}

// Remove um elemento da pilha (desempilha)
int remove_pilha(Pilha *pilha) {
    if (pilha == NULL) {
        printf("Pilha não alocada\n");
        exit(1);
    }

    if (pilha_vazia(pilha)) {
        return -1;
    }

    pilha->index--;
    return pilha->elem[pilha->index];
}

// Consulta o elemento do topo da pilha
int consulta_topo(Pilha *pilha) {
    if (pilha == NULL) {
        printf("Pilha não alocada\n");
        exit(1);
    }

    if (pilha_vazia(pilha)) {
        return -1;
    }

    return pilha->elem[pilha->index - 1];
}

// Imprime os elementos da pilha
void imprime_pilha(Pilha *pilha) {
    if (pilha == NULL) {
        printf("Pilha não alocada\n");
        exit(1);
    }

    for (int i = 0; i < pilha->index; i++) {
        printf("%d ", pilha->elem[i]);
    }
    printf("\n");
}

// Libera a pilha
void libera_pilha(Pilha *pilha) {
    if (pilha == NULL) {
        printf("Pilha não alocada\n");
        exit(1);
    }
    free(pilha);
}
