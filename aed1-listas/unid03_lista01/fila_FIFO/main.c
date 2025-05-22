#include <stdio.h>
#include "fila.h"

int main() {
    printf("Criando...\n");
    Fila* f = criaFila();
    
    printf("\tTamanho da fila: %d\n", tamanhoFila(f));

    filaVazia(f);
    filaCheia(f);

    printf("Inserindo...\n");
    int add = insereFila(f, 10);
    printf("\tElemento inserido: %d\n", add);
    add = insereFila(f, 20);
    printf("\tElemento inserido: %d\n", add);
    add = insereFila(f, 30);
    printf("\tElemento inserido: %d\n", add);
    printf("\tTamanho da fila: %d\n", tamanhoFila(f));
    printf("\tElemento no inicio: %d\n\n", consultaFila(f));

    printf("Removendo...\n");
    int deleted = removeFila(f);
    printf("\tElemento removido: %d\n", deleted);
    printf("\tTamanho da fila: %d\n", tamanhoFila(f));
    printf("\tElemento no inicio: %d\n\n", consultaFila(f));

    printf("Inserindo...\n");
    add = insereFila(f, 40);
    printf("\tElemento inserido: %d\n", add);
    add = insereFila(f, 50);
    printf("\tElemento inserido: %d\n\n", add);

    printf("Imprimindo...\n");
    printf("(Inicio)\n");
    imprimeFila(f);

    printf("\n");
    printf("Destruindo...\n");

    liberaFila(f);
    return 0;
}