#include <stdio.h>

int ackermann(int m, int n) {

    // Caso base 1 (m == 0), retorna n + 1
    if (m == 0) {
        return n + 1;
    }

    // Caso base 2 (m > 0 e n == 0), retorna ackermann(m - 1, 1)
    if (n == 0) {
        return ackermann(m - 1, 1);
    }

    // Caso geral, retorna ackermann(m - 1, ackermann(m, n - 1))
    return ackermann(m - 1, ackermann(m, n - 1));
}

int main() {
    
    int m, n;
    scanf("%d %d", &m, &n);

    printf("%d\n", ackermann(m, n));

    return 0;
}
