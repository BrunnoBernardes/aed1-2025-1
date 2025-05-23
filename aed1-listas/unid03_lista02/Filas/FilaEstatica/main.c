#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

int main() {
    printf("Criando filas...\n");
    Fila* fi = cria_Fila();
    Fila* fi2 = cria_Fila();
    Fila* fi3 = cria_Fila();

    printf("Preenchendo a primeira fila...\n");
    for (int i = 1; i <= 5; i++) {
        insere_Fila(fi, i);
    }

    printf("Copiando a fila...\n");
    copia_Fila(fi, fi2);
    printf("\tFila original:\n");
    imprime_Fila(fi);
    printf("\tFila copiada:\n");
    imprime_Fila(fi2);
    
    printf("Preenchendo com mais valores a segunda fila...\n");
    for (int i = 20; i <= 80; i+=4) {
        insere_Fila(fi2, i);
    }

    printf("Intercalando...\n");
    intercala_Filas(fi, fi2, fi3);
    printf("Removendo elementos das filas originais...\n");
    while (remove_Fila(fi) && remove_Fila(fi2)) {
        // Continue removendo elementos até que uma das filas esteja vazia
    }
    printf("\tFila original apos remocao:\n");
    imprime_Fila(fi);
    printf("\tFila copiada apos remocao:\n");
    imprime_Fila(fi2);
    printf("\tFila resultante apos intercalacao:\n");
    imprime_Fila(fi3);

    printf("Liberando filas...\n");
    libera_Fila(fi);
    libera_Fila(fi2);
    libera_Fila(fi3);
    printf("Filas liberadas com sucesso.\n");
    return 0;
}