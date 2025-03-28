#include <stdlib.h>
#include "cubo.h"

// Cria um cubo com o lado especificado
Cubo* criarCubo(float lado) {
    Cubo* c = (Cubo*) malloc(sizeof(Cubo));
    if (c != NULL) {
        c->lado = lado;
    }
    return c;
}

// Retorna o lado do cubo
float obterLado(Cubo* c) {
    return c->lado;
}

// Calcula a área superficial do cubo
float calcularArea(Cubo* c) {
    return 6 * (c->lado * c->lado);
}

// Calcula o volume do cubo
float calcularVolume(Cubo* c) {
    return c->lado * c->lado * c->lado;
}

// Libera a memória alocada para o cubo
void liberarCubo(Cubo* c) {
    free(c);
}
