#include <stdio.h>
#include "lista.h"

int main() {
    Lista* l = criaLista();
    if (l == NULL) {
        printf("Erro ao criar a lista!\n");
        return 1;
    }

    if (listaVazia(l)) printf("Lista vazia.\n");
    else printf("Lista nao esta vazia.\n");

    insereInicio(l, 20);
    insereFim(l, 50);
    insereOrdenado(l, 30);
    insereOrdenado(l, 15);
    insereFim(l, 70);
    insereFim(l, 5);
    insereInicio(l, 10);
    imprimeLista(l);

    int valor;
    if (consultaIndice(l, 2, &valor)) {
        printf("Elemento no indice 2: %d\n", valor);
    }

    if (consultaValor(l, 50, &valor)) {
        printf("Elemento 50 encontrado no indice: %d\n", valor);
    }

    if (listaCheia(l)) printf("Lista cheia.\n");
    else printf("Lista nao esta cheia.\n");

    removeInicio(l);
    removeFim(l);
    removeElemento(l, 30);

    imprimeLista(l);

    printf("Tamanho atual da lista: %d\n", tamanhoLista(l));

    if (listaVazia(l)) printf("Lista vazia.\n");
    else printf("Lista nao esta vazia.\n");

    if (listaCheia(l)) printf("Lista cheia.\n");
    else printf("Lista nao esta cheia.\n");

    liberaLista(l);
    return 0;
}
