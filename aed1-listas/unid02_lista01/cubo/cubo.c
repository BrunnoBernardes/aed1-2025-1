#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cubo.h"

// Cria um cubo com o lado especificado
Cubo* criarCubo(float lado) {
    Cubo* c = (Cubo*) malloc(sizeof(Cubo));
    if (c == NULL) {
        printf("Erro ao alocar memória para o cubo.\n");
        return NULL;
    } else if (lado <= 0) {
        printf("Lado inválido. O lado deve ser maior que zero.\n");
        free(c);
        return NULL;
    } else {
        c->lado = lado;
    }
    return c;
}

// Retorna o lado do cubo
float obterLado(Cubo* c) {
    if (c == NULL) {
        printf("Cubo não inicializado.\n");
        return NAN;
    }
    return c->lado;
}

// Calcula a área superficial do cubo
float calcularArea(Cubo* c) {
    if (c == NULL) {
        printf("Cubo não inicializado.\n");
        return NAN;
    }
    return 6 * (c->lado * c->lado);
}

// Calcula o volume do cubo
float calcularVolume(Cubo* c) {
    if (c == NULL) {
        printf("Cubo não inicializado.\n");
        return NAN;
    }
    return c->lado * c->lado * c->lado;
}

// Libera a memória alocada para o cubo
void liberarCubo(Cubo* c) {
    if (c == NULL) {
        printf("Cubo não inicializado.\n");
        return;
    }
    free(c);
}
