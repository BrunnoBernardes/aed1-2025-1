#include <stdio.h>
#include "conjunto.h"

// 1
// Funções para manipulação de conjuntos
int criaConjunto(Conjunto *c) {
    c->tamanho = 0;
    return SUCESSO;
}

// 2
// Verifica se o conjunto está vazio
int conjuntoVazio(Conjunto c) {
    if (c.tamanho == 0) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

// 3
// Insere um elemento no conjunto
int insereElementoConjunto(int x, Conjunto *c) {
    if (pertenceConjunto(x, *c) == TRUE || c->tamanho >= MAX) {
        return FALHA;
    }
    c->elementos[c->tamanho++] = x;
    return SUCESSO;
}

// 4
// Exclui um elemento do conjunto
int excluirElementoConjunto(int x, Conjunto *c) {
    int i, j;
    for (i = 0; i < c->tamanho; i++) {
        if (c->elementos[i] == x) {
            for (j = i; j < c->tamanho - 1; j++) {
                c->elementos[j] = c->elementos[j + 1];
            }
            c->tamanho--;
            return SUCESSO;
        }
    }
    return FALHA;
}

// 5
// Retorna o tamanho do conjunto
int tamanhoConjunto(Conjunto c) {
    return c.tamanho;
}

// 6
// Retorna a quantidade de elementos maiores que x
int maior(int x, Conjunto c) {
    int cont = 0;
    int i;
    for (i = 0; i < c.tamanho; i++) {
        if (c.elementos[i] > x) {
            cont++;
        }
    }
    return cont;
}

// 7
// Retorna a quantidade de elementos menores que x
int menor(int x, Conjunto c) {
    int cont = 0;
    int i;
    for (i = 0; i < c.tamanho; i++) {
        if (c.elementos[i] < x) {
            cont++;
        }
    }
    return cont;
}

// 8
// Verifica se um elemento pertence ao conjunto
int pertenceConjunto(int x, Conjunto c) {
    int i;
    for (i = 0; i < c.tamanho; i++) {
        if (c.elementos[i] == x) {
            return TRUE;
        }
    }
    return FALSE;
}

// 9
// Verifica se dois conjuntos são idênticos
int conjuntosIdenticos(Conjunto c1, Conjunto c2) {
    if (c1.tamanho != c2.tamanho) {
        return FALSE;
    }
    int i;
    for (i = 0; i < c1.tamanho; i++) {
        if (!pertenceConjunto(c1.elementos[i], c2)) {
            return FALSE;
        }
    }
    return TRUE;
}

// 10
// Verifica se o conjunto c1 é subconjunto de c2
int subconjunto(Conjunto c1, Conjunto c2) {
    int i;
    for (i = 0; i < c1.tamanho; i++) {
        if (!pertenceConjunto(c1.elementos[i], c2)) {
            return FALSE;
        }
    }
    return TRUE;
}

// 15
// Ordena e exibe o conjunto em ordem crescente ou decrescente
void mostraConjunto(Conjunto c, int ordem) {
    int i, j;
    if (ordem == CRESCENTE) {
        for (i = 0; i < c.tamanho - 1; i++) {
            for (j = i + 1; j < c.tamanho; j++) {
                if (c.elementos[i] > c.elementos[j]) {
                    int tmp = c.elementos[i];
                    c.elementos[i] = c.elementos[j];
                    c.elementos[j] = tmp;
                }
            }
        }
    } else {
        for (i = 0; i < c.tamanho - 1; i++) {
            for (j = i + 1; j < c.tamanho; j++) {
                if (c.elementos[i] < c.elementos[j]) {
                    int tmp = c.elementos[i];
                    c.elementos[i] = c.elementos[j];
                    c.elementos[j] = tmp;
                }
            }
        }
    }

    printf("{ ");
    for (i = 0; i < c.tamanho; i++)
        printf("%d ", c.elementos[i]);
    printf("}\n");
}
