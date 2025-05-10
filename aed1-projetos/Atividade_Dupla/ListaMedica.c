/*
    Dupla:
    Brunno Bernardes - 202405846
    Lourenço Tabosa - 202401799
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ListaMedica.h" //inclui os Prototipos

// Definicao do tipo lista

struct no {
    Paciente dados;
    struct no *prox;
};

struct lista {
    No *inicio;
};

Lista *cria_lista(){
    Lista *li = (Lista *)malloc(sizeof(Lista));

    if (li != NULL)
        li->inicio = NULL;

    return li;
}

void libera_lista(Lista *li){
    if (li != NULL){
        No *no;

        while ((li->inicio) != NULL){
            no = li->inicio;
            li->inicio = (li->inicio)->prox;
            free(no);
        }
        free(li);
    }
}

int insere_lista_final(Lista *li, Paciente p){
    if (li == NULL)
        return 0;
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
        return 0;
    novo->dados = p;
    novo->prox = NULL;

    if ((li->inicio) == NULL){ // lista vazia: insere inicio
        li->inicio = novo;
    }
    else{
        No *aux = li->inicio;
        while (aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    return 1;
}

int insere_lista_inicio(Lista *li, Paciente p){
    if (li == NULL)
        return 0;
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
        return 0;
    novo->dados = p;
    novo->prox = (li->inicio);
    li->inicio = novo;
    return 1;
}

int insere_lista_ordenada(Lista *li, Paciente p){
    if (li == NULL)
        return 0;
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
        return 0;
    novo->dados = p;

    if ((li->inicio == NULL || p.cod_paciente < li->inicio->dados.cod_paciente) == NULL){ // lista vazia: insere inicio
        novo->prox = NULL;
        li->inicio = novo;
        return 1;
    }

    No *ant = li->inicio;
    No *atual = li->inicio->prox;
    while (atual != NULL && atual->dados.cod_paciente < p.cod_paciente){
        ant = atual;
        atual = atual->prox;
    }

    ant->prox = novo;
    novo->prox = atual;
    return 1;
}

int remove_lista(Lista *li, int cod){
    if (li == NULL)
        return 0;
    if (li->inicio == NULL) // lista vazia
        return 0;
        
    No *ant = NULL;
    No* no = li->inicio;
    while (no != NULL && no->dados.cod_paciente != cod){
        ant = no;
        no = no->prox;
    }

    if (no == NULL) // nao encontrado
        return 0;

    if (ant == NULL) // remover o primeiro?
        li->inicio = no->prox;
    else
        ant->prox = no->prox;
    
    free(no);
    return 1;
}

int remove_lista_inicio(Lista *li)
{
    if (li == NULL)
        return 0;
    if ((li->inicio) == NULL) // lista vazia
        return 0;

    No* no = li->inicio;
    li->inicio = no->prox;
    free(no);
    return 1;
}

int remove_lista_final(Lista *li)
{
    if (li == NULL)
        return 0;
    if ((li->inicio) == NULL) // lista vazia
        return 0;

    No* ant = NULL;
    No* no = li->inicio;
    
    while (no->prox != NULL)
    {
        ant = no;
        no = no->prox;
    }

    if (ant == NULL) // remover o primeiro?
        li->inicio = NULL;
    else
        ant->prox = NULL;
    free(no);
    return 1;
}

int consulta_lista_cod(Lista *li, int cod){
    if (li == NULL)
        return 0;

    No *atual = li->inicio;

    while (atual != NULL)
        if (atual->dados.cod_paciente == cod)
        {
            printf("NOME: %s\n", atual->dados.nome);
            printf("CODIGO: %d\n", atual->dados.cod_paciente);
            printf("ID CID: %d\n", atual->dados.cid_id);
            printf("NOME CID: %s\n", atual->dados.cid_nome);
            printf("SITUACAO: %s\n", atual->dados.situacao_vida ? "Vivo" : "Falecido");
            printf("MEDICO: %s (ID: %d)\n", atual->dados.id_medico, atual->dados.medico.id_medico);
            return 1;
        }
    atual = atual->prox;
    
    printf("PACIENTE COM CODIGO %d NAO ENCONTRADO.\n", cod);
    return 0;
}


void imprime_lista(Lista *li)
{
    if (li == NULL)
        return;

    No* no = li->inicio;
    while (no != NULL)
    {
        printf("NOME: %s\n", no->dados.nome);
        printf("CÓDIGO: %d\n", no->dados.cod_paciente);
        printf("ID CID: %d\n", no->dados.cid_id);
        printf("NOME CID: %s\n", no->dados.cid_nome);
        printf("SITUAÇÃO: %s\n", no->dados.situacao_vida ? "Vivo" : "Falecido");
        printf("MÉDICO: %s (ID: %d)\n", no->dados.medico.nome, no->dados.medico.id_medico);

        printf("-------------------------------\n");

        no = no->prox;
    }
}
