#include <stdio.h>
#include "lista.h"

int main() {
    printf("Criando...\n");
    Lista* l = criaLista();


    printf("\tTamanho da lista: %d\n", tamanhoLista(l));

    listaVazia(l);
    listaCheia(l);

    printf("Inserindo...\n");
    insereInicio(l, 20);
    printf("\tElemento inserido no inicio: %d\n", 20);
    insereFim(l, 50);
    printf("\tElemento inserido no fim: %d\n", 50);
    insereOrdenado(l, 30);
    printf("\tElemento inserido ordenado: %d\n", 30);
    insereOrdenado(l, 15);
    printf("\tElemento inserido ordenado: %d\n", 15);
    insereFim(l, 70);
    printf("\tElemento inserido no fim: %d\n", 70);
    insereFim(l, 5);
    printf("\tElemento inserido no fim: %d\n", 5);
    insereInicio(l, 10);
    printf("\tElemento inserido no inicio: %d\n", 10);
    
    printf("\tTamanho da lista: %d\n", tamanhoLista(l));

    printf("Imprimindo...\n");
    imprimeLista(l);

    printf("Consultando...\n");
    consultaValor(l, 30);
    
    consultaIndice(l, 2);

    printf("Removendo...\n");
    removeInicio(l);
    printf("\tElemento removido do inicio.\n");
    removeFim(l);
    printf("\tElemento removido do fim.\n");
    removeElemento(l, 30);
    printf("\tElemento removido: %d\n", 30);

    printf("\tTamanho da lista: %d\n", tamanhoLista(l));

    printf("Imprimindo...\n");
    imprimeLista(l);

    printf("Destruindo...\n");
    liberaLista(l);
    return 0;
}
