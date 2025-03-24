#include <stdio.h>

void imprimirNaturais(int atual, int n) {

    // Caso base (n == 0), ou também, caso de parada da recursão
    if (atual > n){
        printf("\n");
        return;
    }

    printf("%d", atual);

    if (atual < n){
        printf(" ");
    }
    
    imprimirNaturais(atual + 1, n);
}

int main() {
    
    int n;
    scanf("%d", &n);

    imprimirNaturais(1, n);

    return 0;
}
