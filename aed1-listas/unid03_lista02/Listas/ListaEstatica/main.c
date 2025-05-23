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
    int index;
    consultaValor(l, 30, &index);
    printf("\tElemento %d encontrado no indice: %d\n", 30, index);
    int elem;
    consultaIndice(l, 2, &elem);
    printf("\tBusca no indice %d, elemento encontrado: %d\n", 2, elem);

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

    printf("Inserindo...\n");
    insereInicio(l, 22);
    printf("\tElemento inserido no inicio: %d\n", 22);
    insereInicio(l, 33);
    printf("\tElemento inserido no inicio: %d\n", 33);
    insereInicio(l, 44);
    printf("\tElemento inserido no inicio: %d\n", 44);
    insereInicio(l, 55);
    printf("\tElemento inserido no inicio: %d\n", 55);
    insereInicio(l, 66);
    printf("\tElemento inserido no inicio: %d\n", 66);
    insereInicio(l, 77);
    printf("\tElemento inserido no inicio: %d\n", 77);
    insereInicio(l, 88);
    printf("\tElemento inserido no inicio: %d\n", 88);
    insereInicio(l, 99);
    printf("\tElemento inserido no inicio: %d\n", 99);
    insereInicio(l, 101);
    printf("\tElemento inserido no inicio: %d\n", 101);
    insereInicio(l, 111);
    printf("\tElemento inserido no inicio: %d\n", 111);
    insereInicio(l, 122);
    printf("\tElemento inserido no inicio: %d\n", 122);
    insereInicio(l, 134);
    printf("\tElemento inserido no inicio: %d\n", 134);
    insereInicio(l, 146);
    printf("\tElemento inserido no inicio: %d\n", 146);
    insereInicio(l, 158);
    printf("\tElemento inserido no inicio: %d\n", 158);

    printf("Removendo...\n");
    removeNPrimeirosElementos(l, 5);
    printf("\tRemovidos %d elementos do inicio.\n", 5);
    removeNUltimosElementos(l, 5);
    printf("\tRemovidos %d elementos do fim.\n", 5);

    printf("Imprimindo...\n");
    printf("\tQuantidade de pares: %d\n", quantidadePares(l));
    printf("\tSoma da lista: %d\n", somaLista(l));
    printf("\tMedia da lista: %d\n", mediaLista(l));
    printf("\tMaior valor: %d\n", maiorValor(l));
    printf("\tMenor valor: %d\n", menorValor(l));
    printf("\tPosicao maior valor: %d\n", posicaoMaiorValor(l));
    printf("\tPosicao menor valor: %d\n", posicaoMenorValor(l));
    printf("\tNumero nos impares: %d\n", numeroNosImpares(l));

    printf("Imprimindo...\n");
    imprimeLista(l);
    printf("Tamanho da lista: %d\n", tamanhoLista(l));
    
    printf("Destruindo...\n");
    liberaLista(l);
    return 0;
}
