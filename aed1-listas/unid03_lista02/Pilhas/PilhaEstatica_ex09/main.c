#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "pilha.h"

int verifica_palindromo(const char* frase);

int main() {
    char entrada[MAX];

    
    printf("Digite uma frase: ");
    fgets(entrada, MAX, stdin);
    entrada[strcspn(entrada, "\n")] = '\0'; // remove \n do final

    if (verifica_palindromo(entrada)) {
        printf("E palindromo!\n");
    } else {
        printf("Nao e palindromo.\n");
    }

    return 0;
}
