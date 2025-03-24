#include <stdio.h>

int fibonacci(int n) {

    // Caso base 1 (n == 0), retorna 0 para impressão
    if (n == 0) {
        return 0;
    }

    // Caso base 2 (n == 1), retorna 1 para impressão
    if (n == 1) {
        return 1;
    }

    // Caso geral, retorna a soma dos dois números anteriores de n
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {

    int n;
    scanf("%d", &n);

    int i;
    for (i = 0; i <= n; i++) {
        printf("%d", fibonacci(i));

        if (i < n) {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}
