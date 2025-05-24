#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"

int main() {
    char expressao[256];

    printf("Digite a expressao: ");
    fgets(expressao, sizeof(expressao), stdin);
    expressao[strcspn(expressao, "\n")] = '\0'; // Remove \n

    // Inicializa a pilha dentro da funcao parentizacao
    if (verifica_parentizacao(expressao)) {
        printf("Expressao com parentizacao CORRETA!\n");
    } else {
        printf("Expressao com parentizacao INCORRETA!\n");
    }

    return 0;
}
