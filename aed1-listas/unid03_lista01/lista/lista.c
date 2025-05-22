#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista {
    int dados[MAX];
    int qtd;
};

// Cria e inicializa uma nova lista
Lista* criaLista() {
    Lista* l = (Lista*) malloc(sizeof(Lista));

    if (l == NULL) {
        printf("Nao foi possivel alocar.\n");
        exit(1);
    }

    inicializaLista(l);

    return l;
}

// Inicializa a lista
void inicializaLista(Lista* l) {
    if (l == NULL) {
        printf("Lista nao alocada\n");
        exit(1);
    }
    l->qtd = 0;
}

// Libera a memória alocada para a lista
void liberaLista(Lista* l) {
    free(l);
}

// Retorna o tamanho atual da lista
int tamanhoLista(Lista* l) {
    if (l == NULL) {
        printf("Lista nao alocada\n");
        exit(1);
    }
    return l->qtd;
}

// Verifica se a lista está vazia
int listaVazia(Lista* l) {
    if (l == NULL) {
        printf("Lista nao alocada\n");
        exit(1);
    }
    if (l->qtd == 0) {
        printf("Lista vazia!\n");
        return 1;
    }
    return 0;
}

// Verifica se a lista está cheia
int listaCheia(Lista* l) {
    if (l == NULL) {
        printf("Lista nao alocada\n");
        exit(1);
    }
    if (l->qtd == MAX) {
        printf("Lista cheia!\n");
        return 1;
    }
    return 0;
}

// Insere um elemento no inicio da lista
int insereInicio(Lista* l, int elem) {
    if (l == NULL) {
        printf("Lista nao alocada\n");
        exit(1);
    }
    if (listaCheia(l)) {
        return -1;
    }

    int i;
    for (i = l->qtd - 1; i >= 0; i--) {
        l->dados[i + 1] = l->dados[i]; // Desloca os elementos para a direita
    }
    l->dados[0] = elem;
    l->qtd++;
    return 1;
}

// Insere um elemento no final da lista
int insereFim(Lista* l, int elem) {
    if (l == NULL) {
        printf("Lista nao alocada\n");
        exit(1);
    }
    if (listaCheia(l)) {
        return -1;
    }

    l->dados[l->qtd] = elem;
    l->qtd++;
    return 1;
}

// Insere um elemento na posição correta para manter a lista ordenada
int insereOrdenado(Lista* l, int elem) {
    if (l == NULL) {
        printf("Lista nao alocada\n");
        exit(1);
    }
    if (listaCheia(l)) {
        return -1;
    }

    int i = 0, j;
    while (i < l->qtd && l->dados[i] < elem) i++; // Encontra a posição correta para inserir o elemento
    for (j = l->qtd - 1; j >= i; j--) {
        l->dados[j + 1] = l->dados[j]; // Desloca os elementos para a direita a partir do elemento encontrado 
    }
    l->dados[i] = elem;
    l->qtd++;
    return 1;
}

// Remove o primeiro elemento da lista
int removeInicio(Lista* l) {
    if (l == NULL) {
        printf("Lista nao alocada\n");
        exit(1);
    }
    if (listaVazia(l)) {
        return -1;
    }

    for (int i = 0; i < l->qtd - 1; i++) {
        l->dados[i] = l->dados[i + 1]; // Desloca os elementos para a esquerda
    }
    l->qtd--;
    return 1;
}

// Remove o último elemento da lista
int removeFim(Lista* l) {
    if (l == NULL) {
        printf("Lista nao alocada\n");
        exit(1);
    }
    if (listaVazia(l)) {
        return -1;
    }

    l->qtd--;
    return 1;
}

// Remove um elemento específico da lista
int removeElemento(Lista* l, int elem) {
    if (l == NULL) {
        printf("Lista nao alocada\n");
        exit(1);
    }
    if (listaVazia(l)) {
        return -1;
    }

    int i = 0, j;
    while (i < l->qtd && l->dados[i] != elem) i++; // Encontra o elemento a ser removido
    if (i == l->qtd) {
        printf("Elemento nao encontrado!\n");
        return 0;
    }

    for (j = i; j < l->qtd - 1; j++) {
        l->dados[j] = l->dados[j + 1]; // Desloca os elementos para a esquerda a partir do elemento encontrado
    }
    l->qtd--;
    return 1;
}

// Consulta o índice de um elemento dado o seu valor
int consultaValor(Lista* l, int elem, int* index) {
    if (l == NULL) {
        printf("Lista nao alocada\n");
        exit(1);
    }
    if (listaVazia(l)) {
        return -1;
    }

    int i;
    for (i = 0; i < l->qtd; i++) {
        if (l->dados[i] == elem) {
            *index = i;
            return 1;
        }
    }
    if (i == l->qtd) {
        printf("\tElemento nao encontrado\n");
        return 0;
    }
    return 1;
}

// Consulta o valor de um elemento dado o seu índice
int consultaIndice(Lista* l, int index, int* elem) {
    if (l == NULL) {
        printf("Lista nao alocada\n");
        exit(1);
    }
    if (listaVazia(l)) {
        return -1;
    }
    if (index < 0 || index >= l->qtd) {
        printf("Indice invalido!\n");
        return 0;
    }

    *elem = l->dados[index];
    return 1;
}

// Imprime todos os elementos da lista
void imprimeLista(Lista* l) {
    if (l == NULL) {
        printf("Lista nao alocada\n");
        exit(1);
    }
    
    int i;
    for (i = 0; i < l->qtd; i++) {
        printf("\t%d\n", l->dados[i]);
    }
}