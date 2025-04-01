#ifndef CONJUNTO_H
#define CONJUNTO_H

#define MAX 100
#define SUCESSO 1
#define FALHA 0
#define TRUE 1
#define FALSE 0
#define CRESCENTE 1
#define DECRESCENTE 0

typedef struct {
    int elementos[MAX];
    int tamanho;
} Conjunto;

// 1
// Funções para manipulação de conjuntos
int criaConjunto(Conjunto *c);

// 2
// Verifica se o conjunto está vazio
int conjuntoVazio(Conjunto c);

// 3
// Insere um elemento no conjunto
int insereElementoConjunto(int x, Conjunto *c);

// 4
// Exclui um elemento do conjunto
int excluirElementoConjunto(int x, Conjunto *c);

// 5
// Retorna o tamanho do conjunto
int tamanhoConjunto(Conjunto c);

// 6
// Retorna a quantidade de elementos maiores que x
int maior(int x, Conjunto c);

// 7
// Retorna a quantidade de elementos menores que x
int menor(int x, Conjunto c);

// 8
// Verifica se um elemento pertence ao conjunto
int pertenceConjunto(int x, Conjunto c);

// 9
// Verifica se dois conjuntos são idênticos
int conjuntosIdenticos(Conjunto c1, Conjunto c2);

// 10
// Verifica se o conjunto c1 é subconjunto de c2
int subconjunto(Conjunto c1, Conjunto c2);

// 15
// Verifica se o conjunto c1 é superconjunto de c2
void mostraConjunto(Conjunto c, int ordem);

#endif
