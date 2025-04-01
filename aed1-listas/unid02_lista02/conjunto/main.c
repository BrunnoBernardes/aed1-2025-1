#include <stdio.h>
#include "conjunto.h"

int main()
{
    Conjunto A, B;
    int resultado, conjunto = 0, op, valor;

    criaConjunto(&A);
    criaConjunto(&B);

    // Escolha inicial do conjunto
    do {
        printf("\nQual conjunto deseja manipular?\n");
        printf("1 - A\n");
        printf("2 - B\n");
        printf("Escolha: ");
        resultado = scanf("%d", &conjunto);

        if (resultado != 1) {
            while (getchar() != '\n');
            printf("Entrada invalida. Por favor, digite um numero.\n");
            conjunto = 0;
        } else if (conjunto != 1 && conjunto != 2) {
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (conjunto != 1 && conjunto != 2);

    do {
        printf("\nMenu (Conjunto %c):\n", conjunto == 1 ? 'A' : 'B');
        printf("1 - Inserir elemento em %c\n", conjunto == 1 ? 'A' : 'B');
        printf("2 - Remover elemento em %c\n", conjunto == 1 ? 'A' : 'B');
        printf("3 - Mostrar conjunto %c\n", conjunto == 1 ? 'A' : 'B');
        printf("4 - Verificar o conjunto %c esta vazio\n", conjunto == 1 ? 'A' : 'B');
        printf("5 - Tamanho do conjunto %c\n", conjunto == 1 ? 'A' : 'B');
        printf("6 - Quantos > x e do conjunto %c\n", conjunto == 1 ? 'A' : 'B');
        printf("7 - Quantos < x e do conjunto %c\n", conjunto == 1 ? 'A' : 'B');
        printf("8 - Verificar se x pertence ao conjunto %c\n", conjunto == 1 ? 'A' : 'B');
        printf("9 - Verificar se os conjuntos sao identicos\n");
        printf("10 - Verificar se %c e subconjunto do outro\n", conjunto == 1 ? 'A' : 'B');
        printf("15 - Ordenar conjunto %c e mostrar em ordem crescente ou decrescente\n", conjunto == 1 ? 'A' : 'B');
        printf("99 - Mudar conjunto\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);

        switch (op) {
        case 1:
            printf("Digite o elemento a inserir: ");
            scanf("%d", &valor);
            if (insereElementoConjunto(valor, conjunto == 1 ? &A : &B))
                printf("Inserido com sucesso!\n");
            else
                printf("Falha ao inserir.\n");
            break;
        case 2:
            printf("Digite o elemento a remover: ");
            scanf("%d", &valor);
            if (excluirElementoConjunto(valor, conjunto == 1 ? &A : &B))
                printf("Removido com sucesso!\n");
            else
                printf("Elemento nao encontrado.\n");
            break;
        case 3:
            mostraConjunto(conjunto == 1 ? A : B, CRESCENTE);
            break;
        case 4:
            printf(conjuntoVazio(conjunto == 1 ? A : B) ? "Vazio\n" : "Nao vazio\n");
            break;
        case 5:
            printf("Tamanho: %d\n", tamanhoConjunto(conjunto == 1 ? A : B));
            break;
        case 6:
            printf("Digite x: ");
            scanf("%d", &valor);
            printf("Maiores que %d: %d\n", valor, maior(valor, conjunto == 1 ? A : B));
            break;
        case 7:
            printf("Digite x: ");
            scanf("%d", &valor);
            printf("Menores que %d: %d\n", valor, menor(valor, conjunto == 1 ? A : B));
            break;
        case 8:
            printf("Digite x: ");
            scanf("%d", &valor);
            printf(pertenceConjunto(valor, conjunto == 1 ? A : B) ? "Pertence\n" : "Nao pertence\n");
            break;
        case 9:
            printf(conjuntosIdenticos(A, B) ? "Identicos\n" : "Diferentes\n");
            break;
        case 10:
            if (conjunto == 1)
                printf(subconjunto(A, B) ? "Subconjunto\n" : "Nao e subconjunto\n");
            else
                printf(subconjunto(B, A) ? "Subconjunto\n" : "Nao e subconjunto\n");
            break;
            case 15:
            printf("Escolha a ordem (1 para crescente, 0 para decrescente): ");
            scanf("%d", &valor);
            mostraConjunto(conjunto == 1 ? A : B, valor);
            break;
        case 99:
            do {
                printf("\nEscolha o conjunto:\n");
                printf("1 - A\n");
                printf("2 - B\n");
                printf("Escolha: ");
                resultado = scanf("%d", &conjunto);

                if (resultado != 1) {
                    while (getchar() != '\n');
                    printf("Entrada invalida. Digite um numero.\n");
                    conjunto = 0;
                } else if (conjunto != 1 && conjunto != 2) {
                    printf("Opcao invalida. Tente novamente.\n");
                }
            } while (conjunto != 1 && conjunto != 2);
            break;
        case 0:
            printf("Encerrando programa.\n");
            break;
        default:
            printf("Opcao invalida.\n");
        }

    } while (op != 0);

    return 0;
}