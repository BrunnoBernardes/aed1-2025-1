#include "esfera.h"

// Cria uma esfera com o raio especificado
Esfera* criarEsfera(float raio) {
    Esfera* e = (Esfera*) malloc(sizeof(Esfera));
    if (e == NULL) {
        printf("Erro ao alocar memória para a esfera.\n");
        return NULL;
    } else if (raio <= 0) {
        printf("Raio inválido. O raio deve ser maior que zero.\n");
        free(e);
        return NULL;
    } else {
        e->raio = raio;
    }
    return e;
}

// Retorna o raio da esfera
float obterRaio(Esfera* e) {
    if (e == NULL) {
        printf("Esfera não inicializada.\n");
        return NAN;
    }
    return e->raio;
}

// Calcula a área superficial da esfera
float calcularArea(Esfera* e) {
    if (e == NULL) {
        printf("Esfera não inicializada.\n");
        return NAN;
    }
    return 4 * PI * e->raio * e->raio;
}

// Calcula o volume da esfera
float calcularVolume(Esfera* e) {
    if (e == NULL) {
        printf("Esfera não inicializada.\n");
        return NAN;
    }
    return (4.0 / 3.0) * PI * e->raio * e->raio * e->raio;
}

// Libera a memória alocada para a esfera
void liberarEsfera(Esfera* e) {
    if (e == NULL) {
        printf("Esfera não inicializada.\n");
        return;
    }
    free(e);
}