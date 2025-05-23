#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//Definição do tipo lista
struct elemento{
    struct elemento *ant;
    struct produto dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    
    if (li == NULL) {
        printf("Nao foi possivel alocar.\n");
        exit(1);
    }

    inicializa_lista(li);
    
    return li;
}

void inicializa_lista(Lista* li){
    if (li == NULL) {
        printf("Nao foi possivel alocar.\n");
        exit(1);
    }
    *li = NULL;
}

void libera_lista(Lista* li){
    if (li == NULL) {
        printf("Nao foi possivel alocar.\n");
        exit(1);
    }

    Elem* no;
    while((*li) != NULL){
        no = *li;
        *li = (*li)->prox;
        free(no);
    }
    free(li);
    
}

int tamanho_lista(Lista* li){
    if (li == NULL) {
        printf("Nao foi possivel alocar.\n");
        exit(1);
    }

    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int cadastra_produto(Lista* li, Produto prod){
    if (li == NULL) {
        printf("Nao foi possivel alocar.\n");
        exit(1);
    }

    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        printf("Nao foi possivel alocar.\n");
        exit(1);
    }
    no->dados = prod;
    no->prox = *li;
    no->ant = NULL;

    if(*li != NULL)
        (*li)->ant = no;

    *li = no;
    
    return 1;
}

int remove_lista(Lista* li, int cod){
    if (li == NULL) {
        printf("Nao foi possivel alocar.\n");
        exit(1);
    }

    if(*li == NULL){
        printf("Lista vazia!\n");
        return 0;
    }

    Elem* no = *li;
    while(no != NULL && no->dados.codigo != cod){
        no = no->prox;
    }
    
    if(no == NULL)
        return 0;

    if(no->ant != NULL)
        no->ant->prox = no->prox;
    else
        *li = no->prox;

    if(no->prox != NULL)
        no->prox->ant = no->ant;

    free(no);
    
    return 1;
}

int busca_lista_menor_preco(Lista* li){
    if (li == NULL) {
        printf("Nao foi possivel alocar.\n");
        exit(1);
    }

    if (*li == NULL) {
        printf("Lista vazia!\n");
        return 0;
    }

    Elem* no = *li;
    Elem* menor = no;

    while (no != NULL) {
        if (no->dados.preco < menor->dados.preco) {
            menor = no;
        }
        no = no->prox;
    }

    return menor->dados.codigo;
}

void imprime_lista(Lista* li){
    if (li == NULL) {
        printf("Nao foi possivel alocar.\n");
        exit(1);
    }

    if(*li == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    Elem* no = *li;
    while(no != NULL){
        printf("Codigo: %d\n", no->dados.codigo);
        printf("Nome: %s\n", no->dados.nomeProd);
        printf("Preco: %.2f\n", no->dados.preco);
        printf("Quantidade em estoque: %d\n", no->dados.qtdEstoque);
        printf("\n");
        no = no->prox;
    }
}

int consulta_anterior_e_proximo(Lista* li, int cod, Produto* anterior, Produto* proximo){
    if (li == NULL) {
        printf("Nao foi possivel alocar.\n");
        exit(1);
    }

    if(*li == NULL) {
        printf("Lista vazia!\n");
        return 0;
    }

    Elem* no = *li;
    while(no != NULL && no->dados.codigo != cod){
        no = no->prox;
    }
    
    if(no == NULL) {
        printf("Produto nao encontrado!\n");
        return 0;
    }

    if(no->ant != NULL)
        *anterior = no->ant->dados;
    else
        anterior->codigo = -1;
    
    if(no->prox != NULL)
        *proximo = no->prox->dados;
    else
        proximo->codigo = -1;

    return 1;
}

int removeNprimeirosProdutos(Lista* li, int n){
    if (li == NULL) {
        printf("Nao foi possivel alocar.\n");
        exit(1);
    }

    if(*li == NULL) {
        printf("Lista vazia!\n");
        return 0;
    }

    if(n > tamanho_lista(li)){
        printf("Quantidade de produtos a remover maior que a lista!\n");
        return 0;
    }

    Elem* no = *li;
    for(int i = 0; i < n; i++){
        *li = (*li)->prox;
        free(no);
        no = *li;
    }

    if(*li != NULL)
        (*li)->ant = NULL;
    
    return 1;
}

int removeNultimosProdutos(Lista* li, int n){
    if (li == NULL) {
        printf("Nao foi possivel alocar.\n");
        exit(1);
    }

    if(*li == NULL) {
        printf("Lista vazia!\n");
        return 0;
    }

    if(n > tamanho_lista(li)){
        printf("Quantidade de produtos a remover maior que a lista!\n");
        return 0;
    }

    Elem* no = *li;
    while(no->prox != NULL){
        no = no->prox;
    }
    
    for (int i = 0; i < n; i++) {
        Elem* anterior = no->ant;
        free(no);
        if (anterior != NULL)
            anterior->prox = NULL;
        else
            *li = NULL; // lista ficou vazia
        no = anterior;
    }
    
    return 1;
}