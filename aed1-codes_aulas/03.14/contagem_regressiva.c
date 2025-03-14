#include <stdio.h>
#include <stdlib.h>

void contagemRegressiva(int num);

int main (){
    int num = 5;
    contagemRegressiva(num);
    return 0;
}

// Função recursiva que faz a contagem regressiva
void contagemRegressiva(int num) {
    if (num == 0) {
        printf("Fogo!\n");
    } else {
        printf("%d\n", num);
        contagemRegressiva(num - 1); // Chamada recursiva
    }
}