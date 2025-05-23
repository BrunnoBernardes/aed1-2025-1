#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

int main() {
    Fila* fila = criaFila();
    int opcao;
    Cliente c;

    do {
        printf("\nBanco - Fila de Atendimento\n");
        printf("1. Adicionar cliente\n");
        printf("2. Chamar proximo cliente\n");
        printf("3. Listar clientes\n");
        printf("4. Quantidade de clientes\n");
        printf("5. Tempo medio de espera\n");
        printf("6. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o codigo do cliente: ");
                scanf("%d", &c.codigo);
                printf("Digite o nome do cliente: ");
                scanf(" %[^\n]", c.nome);
                if (enfileira(fila, c))
                    printf("Cliente adicionado com sucesso!\n");
                else
                    printf("Erro ao adicionar cliente!\n");
                break;
            case 2:
                if (desenfileira(fila, &c))
                    printf("Chamando cliente: %s (codigo %d)\n", c.nome, c.codigo);
                else
                    printf("Fila vazia!\n");
                break;
            case 3:
                printf("Clientes na fila:\n");
                listarFila(fila);
                break;
            case 4:
                printf("Total de clientes na fila: %d\n", tamanhoFila(fila));
                break;
            case 5:
                printf("Tempo medio de espera: %.1f minutos\n", tempoMedioEspera(fila));
                break;
            case 6:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 6);

    liberaFila(fila);
    return 0;
}
