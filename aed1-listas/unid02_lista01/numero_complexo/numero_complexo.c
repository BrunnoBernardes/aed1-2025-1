#include "numero_complexo.h"

// Cria um número complexo com parte real e imaginária especificadas
Complexo* criarComplexo(float real, float imaginario) {
    Complexo* c = (Complexo*) malloc(sizeof(Complexo));
    if (c == NULL) {
        printf("Erro ao alocar memória para o número complexo.\n");
        return NULL;
    } else {
        c->real = real;
        c->imaginario = imaginario;
    }
    return c;
}

// Retorna a soma de dois números complexos
Complexo* somarComplexos(Complexo* c1, Complexo* c2) {
    if (c1 == NULL || c2 == NULL) {
        printf("Um ou ambos os números complexos não estão inicializados.\n");
        return NULL;
    }
    return criarComplexo(c1->real + c2->real, c1->imaginario + c2->imaginario);
}

// Retorna a subtração de dois números complexos
Complexo* subtrairComplexos(Complexo* c1, Complexo* c2) {
    if (c1 == NULL || c2 == NULL) {
        printf("Um ou ambos os números complexos não estão inicializados.\n");
        return NULL;
    }
    return criarComplexo(c1->real - c2->real, c1->imaginario - c2->imaginario);
}

// Retorna a multiplicação de dois números complexos
Complexo* multiplicarComplexos(Complexo* c1, Complexo* c2) {
    if (c1 == NULL || c2 == NULL) {
        printf("Um ou ambos os números complexos não estão inicializados.\n");
        return NULL;
    }
    return criarComplexo(c1->real * c2->real - c1->imaginario * c2->imaginario,
                         c1->real * c2->imaginario + c1->imaginario * c2->real);
}

// Libera a memória alocada para um número complexo
void liberarComplexo(Complexo* c) {
    if (c == NULL) {
        printf("Número complexo não inicializado.\n");
        return;
    }
    free(c);
}