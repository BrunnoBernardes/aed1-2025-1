#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    printf("Criando...\n");
    Pilha *pilha_real = cria_pilha();

    printf("\tTamanho da pilha: %d\n", tamanho_pilha(pilha_real));

    pilha_cheia(pilha_real);
    pilha_vazia(pilha_real);

    printf("Empilhando...\n");
    int add = insere_pilha(pilha_real, 500);
    printf("\tElemento empilhado: %d\n", add);
    add = insere_pilha(pilha_real, 110);
    printf("\tElemento empilhado: %d\n", add);
    printf("\tTamanho da pilha: %d\n", tamanho_pilha(pilha_real));
    printf("\tElemento no topo: %d\n\n", consulta_topo(pilha_real));


    printf("Desempilhando...\n");
    int deleted = remove_pilha(pilha_real);
    printf("\tElemento desempilhado %d\n", deleted);
    printf("\tTamanho da pilha: %d\n", tamanho_pilha(pilha_real));
    printf("\tElemento do topo: %d\n\n", consulta_topo(pilha_real));

    printf("Empilhando...\n");
    add = insere_pilha(pilha_real, 50);
    printf("\tElemento empilhado: %d\n", add);
    add = insere_pilha(pilha_real, 200);
    printf("\tElemento empilhado: %d\n", add);
    printf("\tTamanho da pilha eh: %d\n", tamanho_pilha(pilha_real));
    printf("\tElemento do topo: %d\n\n", consulta_topo(pilha_real));

    printf("Imprimindo...\n");
    printf("(Topo)\n");
    imprime_pilha(pilha_real);

    printf("\n");

    libera_pilha(pilha_real);
    pilha_real = NULL; // Evita acesso a ponteiro inválido
    return 0;
}