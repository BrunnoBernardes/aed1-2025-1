#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    printf("Criando lista...\n");
    Lista* li = cria_lista();
    printf("Lista criada com sucesso!\n");

    Produto prod;
    int opcao, cod;
    float preco;
    Produto anterior, proximo;

    do{
        printf("Escolha uma opcao:\n");
        printf("\t1 - Cadastrar produto\n");
        printf("\t2 - Remover produto\n");
        printf("\t3 - Buscar produto com menor preco\n");
        printf("\t4 - Consultar anterior e proximo\n");
        printf("\t5 - Imprimir lista\n");
        printf("\t6 - Remover N primeiros produtos\n");
        printf("\t7 - Remover N ultimos produtos\n");
        printf("\t8 - Sair\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Digite o codigo do produto: ");
                scanf("%d", &prod.codigo);
                printf("Digite o nome do produto: ");
                scanf("%s", prod.nomeProd);
                printf("Digite o preco do produto: ");
                scanf("%f", &prod.preco);
                printf("Digite a quantidade em estoque: ");
                scanf("%d", &prod.qtdEstoque);
                cadastra_produto(li, prod);
                break;
            case 2:
                printf("Digite o codigo do produto a ser removido: ");
                scanf("%d", &cod);
                remove_lista(li, cod);
                break;
            case 3:
                cod = busca_lista_menor_preco(li);
                if (cod != 0)
                    printf("Produto com menor preco tem codigo: %d\n", cod);
                else
                printf("Produto nao encontrado!\n");
                break;
            case 4:
                 printf("Digite o codigo do produto: ");
                scanf("%d", &cod);
                 if (consulta_anterior_e_proximo(li, cod, &anterior, &proximo)) {
                     if (anterior.codigo != -1) {
                        printf("Produto anterior:\n");
                        printf("Codigo: %d\n", anterior.codigo);
                        printf("Nome: %s\n", anterior.nomeProd);
                        printf("Preco: %.2f\n", anterior.preco);
                        printf("Quantidade em estoque: %d\n", anterior.qtdEstoque);
                    } else {
                        printf("Nao ha produto anterior.\n");
                    }

        if (proximo.codigo != -1) {
            printf("\nProduto proximo:\n");
            printf("Codigo: %d\n", proximo.codigo);
            printf("Nome: %s\n", proximo.nomeProd);
            printf("Preco: %.2f\n", proximo.preco);
            printf("Quantidade em estoque: %d\n", proximo.qtdEstoque);
        } else {
            printf("\nNao ha produto proximo.\n");
        }
    } else {
        printf("Produto nao encontrado!\n");
    }
    break;

            case 5:
                printf("Imprimindo lista...\n");
                imprime_lista(li);
                break;
            case 6:
                printf("Digite a quantidade de produtos a remover do inicio: ");
                scanf("%d", &cod);
                if(removeNprimeirosProdutos(li, cod))
                    printf("Produtos removidos com sucesso!\n");
                else
                    printf("Erro ao remover produtos!\n");
                break;
            case 7:
                printf("Digite a quantidade de produtos a remover do fim: ");
                scanf("%d", &cod);
                if(removeNultimosProdutos(li, cod))
                    printf("Produtos removidos com sucesso!\n");
                else
                    printf("Erro ao remover produtos!\n");
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
        printf("\n");
    } while(opcao != 8);
    printf("Liberando lista...\n");
    libera_lista(li);
    printf("Lista liberada com sucesso!\n");
    
    system("pause"); // Pausa o programa
    return 0;
}

