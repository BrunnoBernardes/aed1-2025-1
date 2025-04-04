#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Define a estrutura do cilindro
typedef struct cilindro {
    float raio;
    float altura;
} Cilindro;

// Cria um cilindro com o raio e altura especificados
Cilindro* criarCilindro(float raio, float altura);

// Retorna o raio do cilindro
float obterRaio(Cilindro* c);

// Retorna a altura do cilindro
float obterAltura(Cilindro* c);

// Calcula a área superficial do cilindro
float calcularArea(Cilindro* c);

// Calcula o volume do cilindro
float calcularVolume(Cilindro* c);

// Libera a memória alocada para o cilindro
void liberarCilindro(Cilindro* c);