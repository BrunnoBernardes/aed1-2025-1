#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Cria e inicializa uma nova lista
Lista* criaLista() {
    Lista* l = (Lista*) malloc(sizeof(Lista));
    if (l != NULL) l->qtd = 0;
    return l;
}

// Libera a memória alocada para a lista
void liberaLista(Lista* l) {
    free(l);
}

// Retorna o tamanho atual da lista
int tamanhoLista(Lista* l) {
    if (l == NULL) return -1;
    return l->qtd;
}

// Verifica se a lista está vazia
int listaVazia(Lista* l) {
    if (l == NULL) return -1;
    return (l->qtd == 0) ? 1 : 0 ;
}

// Verifica se a lista está cheia
int listaCheia(Lista* l) {
    if (l == NULL) return -1;
    return (l->qtd == MAX) ? 1 : 0 ;
}

// Insere um elemento no inicio da lista
int insereInicio(Lista* l, int elem) {
    if (l == NULL || listaCheia(l)) return 0;
    int i;
    for (i = l->qtd - 1; i >= 0; i--) {
        l->dados[i + 1] = l->dados[i];
    }
    l->dados[0] = elem;
    l->qtd++;
    return 1;
}

// Insere um elemento no final da lista
int insereFim(Lista* l, int elem) {
    if (l == NULL || listaCheia(l)) return 0;
    l->dados[l->qtd] = elem;
    l->qtd++;
    return 1;
}

// Insere um elemento na posição correta para manter a lista ordenada
int insereOrdenado(Lista* l, int elem) {
    if (l == NULL || listaCheia(l)) return 0;
    int i = 0, j;
    while (i < l->qtd && l->dados[i] < elem) i++;
    for (j = l->qtd - 1; j >= i; j--) {
        l->dados[j + 1] = l->dados[j];
    }
    l->dados[i] = elem;
    l->qtd++;
    return 1;
}

// Remove o primeiro elemento da lista
int removeInicio(Lista* l) {
    if (l == NULL || listaVazia(l)) return 0;
    for (int i = 0; i < l->qtd - 1; i++) {
        l->dados[i] = l->dados[i + 1];
    }
    l->qtd--;
    return 1;
}

// Remove o último elemento da lista
int removeFim(Lista* l) {
    if (l == NULL || listaVazia(l)) return 0;
    l->qtd--;
    return 1;
}

// Remove um elemento específico da lista
int removeElemento(Lista* l, int elem) {
    if (l == NULL || listaVazia(l)) return 0;
    int i = 0, j;
    while (i < l->qtd && l->dados[i] != elem) i++;
    if (i == l->qtd) return 0;
    for (j = i; j < l->qtd - 1; j++) {
        l->dados[j] = l->dados[j + 1];
    }
    l->qtd--;
    return 1;
}

// Consulta o índice de um elemento dado o seu valor
int consultaValor(Lista* l, int elem, int* pos) {
    if (l == NULL || listaVazia(l)) return 0;
    for (int i = 0; i < l->qtd; i++) {
        if (l->dados[i] == elem) {
            *pos = i;
            return 1;
        }
    }
    return 0;
}

// Consulta o valor de um elemento dado o seu índice
int consultaIndice(Lista* l, int indice, int* elem) {
    if (l == NULL || listaVazia(l) || indice < 0 || indice >= l->qtd) return 0;
    *elem = l->dados[indice];
    return 1;
}

// Imprime todos os elementos da lista
void imprimeLista(Lista* l) {
    if (l == NULL) return;
    printf("Lista: ");
    for (int i = 0; i < l->qtd; i++) {
        printf("%d ", l->dados[i]);
    }
    printf("\n");
}