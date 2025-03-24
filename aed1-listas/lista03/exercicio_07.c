#include <stdio.h>
#include <string.h>

#define MAX_S 5001
#define MAX_NOTAS 6

int notas[6] = {2, 5, 10, 20, 50, 100};
int quantidade[6];
int memo[MAX_S][6];

int contarManeiras(int valor, int i) {

    // Caso base: valor == 0, encontrou uma maneira
    if (valor == 0) {
        return 1;
    }

    // Caso base: valor < 0, não encontrou uma maneira
    if (valor < 0 || i == 6) {
        return 0;
    }

    // Se o estado já foi visitado, retorna o valor armazenado
    if (memo[valor][i] != -1) {
        return memo[valor][i];
    }

    int total = 0;

    // Tenta usar de 0 até o número máximo de notas disponíveis desse tipo
    int q;
    for (q = 0; q <= quantidade[i]; q++) {

        int novo_valor = valor - q * notas[i];

        if (novo_valor < 0) {
            break; // Evita chamadas desnecessárias
        }

        total += contarManeiras(novo_valor, i + 1);
    }

    memo[valor][i] = total;
    return total;
}

int main() {

    int S;
    scanf("%d", &S);

    int i;
    for (i = 0; i < 6; i++) {
        scanf("%d", &quantidade[i]);
    }

    // Inicializa memo com -1 (estado não visitado)
    memset(memo, -1, sizeof(memo));

    printf("%d\n", contarManeiras(S, 0));

    return 0;
}
