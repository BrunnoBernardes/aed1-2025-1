#include <stdio.h>

void inverterNumero(int n) {

    // Caso base: se chegou ao final, para a recursão
    if (n == 0) {
        return;
    }

    printf("%d", n % 10);
    
    // Chamada recursiva para dividir o número por 10
    inverterNumero(n / 10);
}

int main() {
    
    int n;
    scanf("%d", &n);

    inverterNumero(n);
    printf("\n");

    return 0;
}
