#include "cilindro.h"

// Cria um cilindro com o raio e altura especificados
Cilindro* criarCilindro(float raio, float altura) {
    Cilindro* c = (Cilindro*) malloc(sizeof(Cilindro));
    if (c == NULL) {
        printf("Erro ao alocar memória para o cilindro.\n");
        return NULL;
    } else if (raio <= 0 || altura <= 0) {
        printf("Raio ou altura inválidos. Devem ser maiores que zero.\n");
        free(c);
        return NULL;
    } else {
        c->raio = raio;
        c->altura = altura;
    }
    return c;
}

// Retorna o raio do cilindro
float obterRaio(Cilindro* c) {
    if (c == NULL) {
        printf("Cilindro não inicializado.\n");
        return NAN;
    }
    return c->raio;
}

// Retorna a altura do cilindro
float obterAltura(Cilindro* c) {
    if (c == NULL) {
        printf("Cilindro não inicializado.\n");
        return NAN;
    }
    return c->altura;
}

// Calcula a área superficial do cilindro
float calcularArea(Cilindro* c) {
    if (c == NULL) {
        printf("Cilindro não inicializado.\n");
        return NAN;
    }
    return 2 * PI * c->raio * (c->raio + c->altura);
}

// Calcula o volume do cilindro
float calcularVolume(Cilindro* c) {
    if (c == NULL) {
        printf("Cilindro não inicializado.\n");
        return NAN;
    }
    return PI * c->raio * c->raio * c->altura;
}

// Libera a memória alocada para o cilindro
void liberarCilindro(Cilindro* c) {
    if (c == NULL) {
        printf("Cilindro não inicializado.\n");
        return;
    }
    free(c);
}