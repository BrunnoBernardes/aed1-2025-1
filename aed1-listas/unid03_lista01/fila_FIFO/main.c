#include <stdio.h>
#include "fila.h"

int main() {
    Fila* f = criaFila();
    if (f == NULL) {
        printf("Erro ao criar a fila!\n");
        return 1;
    }

    insereFila(f, 10);
    insereFila(f, 20);
    insereFila(f, 30);
    imprimeFila(f);

    int primeiro;
    if (consultaFila(f, &primeiro)) {
        printf("Primeiro elemento: %d\n", primeiro);
    }

    removeFila(f);
    imprimeFila(f);

    liberaFila(f);
    return 0;
}