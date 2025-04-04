#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Definição da estrutura Esfera
typedef struct esfera {
    float raio;
} Esfera;

// Cria uma esfera com o raio especificado
Esfera* criarEsfera(float raio);

// Retorna o raio da esfera
float obterRaio(Esfera* e);

// Calcula a área superficial da esfera
float calcularArea(Esfera* e);

// Calcula o volume da esfera
float calcularVolume(Esfera* e);

// Libera a memória alocada para a esfera
void liberarEsfera(Esfera* e);