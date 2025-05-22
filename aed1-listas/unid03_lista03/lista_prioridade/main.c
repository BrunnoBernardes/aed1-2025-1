#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

int main() {
    printf("Criando...\n");
    FilaPrio* f = criaFila();

    printf("\tTamanho da fila: %d\n", tamanhoFila(f));

    filaVazia(f);
    filaCheia(f);

    printf("Inserindo...\n");
    Elemento e1 = { .dado = 10, .prioridade = 3 };
    Elemento e2 = { .dado = 20, .prioridade = 1 };
    Elemento e3 = { .dado = 30, .prioridade = 2 };

    insereFila(f, e1);
    printf("\tElemento inserido: %d\n", e1.dado);
    insereFila(f, e2);
    printf("\tElemento inserido: %d\n", e2.dado);
    insereFila(f, e3);
    printf("\tElemento inserido: %d\n", e3.dado);
    printf("\tTamanho da fila: %d\n", tamanhoFila(f));
    printf("\n");

    printf("Imprimindo...\n");
    imprimeFila(f);
    printf("\n");


    printf("Consultando...\n");
    consultaFila(f, &e1);
    printf("\tElemento de maior prioridade: %d\n\n", e1.dado);

    printf("Removendo...\n");
    removeFila(f);
    printf("\tTamanho da fila: %d\n\n", tamanhoFila(f));
    
    printf("Consultando...\n");
    consultaFila(f, &e1);
    printf("\tElemento de maior prioridade: %d\n\n", e1.dado);
    
    printf("Removendo...\n");
    removeFila(f);
    printf("\tTamanho da fila: %d\n\n", tamanhoFila(f));

    printf("Consultando...\n");    
    consultaFila(f, &e1);
    printf("\tElemento de maior prioridade: %d\n\n", e1.dado);
    
    printf("Imprimindo...\n");
    imprimeFila(f);

    printf("\n");
    printf("Destruindo...\n");

    liberaFila(f);
    return 0;
}