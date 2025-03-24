#include <stdio.h>

#define MAXN 10001

int pai[MAXN];

// Função que encontra o representante (com compressão de caminho)
int encontrar(int x) {

    if (pai[x] != x) {
        pai[x] = encontrar(pai[x]);
    }

    return pai[x];
}

// Função para unir dois conjuntos
void unir(int a, int b) {

    int ra = encontrar(a);
    int rb = encontrar(b);
    
    if (ra != rb) {
        pai[rb] = ra;  // Une os conjuntos
    }
}

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    // Inicializa cada pessoa como seu próprio "pai"
    int i;
    for (i = 1; i <= n; i++) {
        pai[i] = i;
    }

    // Processa os pares de pessoas da mesma família
    for (i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        unir(a, b);
    }

    // Conta quantos representantes únicos existem (ou seja, famílias distintas)
    int total_familias = 0;
    for (i = 1; i <= n; i++) {
        if (pai[i] == i) total_familias++;
    }

    printf("%d\n", total_familias);

    return 0;
}
