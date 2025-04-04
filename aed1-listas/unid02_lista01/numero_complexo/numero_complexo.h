#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definição da estrutura Complexo
typedef struct complexo {
    float real;
    float imaginario;
} Complexo;

// Função para criar um número complexo
Complexo* criarComplexo(float real, float imaginario);

// Função para somar dois números complexos
Complexo* somarComplexos(Complexo* c1, Complexo* c2);

// Função para subtrair dois números complexos
Complexo* subtrairComplexos(Complexo* c1, Complexo* c2);

// Função para multiplicar dois números complexos
Complexo* multiplicarComplexos(Complexo* c1, Complexo* c2);

// Libera a memória alocada para um número complexo
void liberarComplexo(Complexo* c);