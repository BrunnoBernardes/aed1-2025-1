#include "numero_complexo.h"

int main() {
    Complexo* c1 = criarComplexo(3.0, 4.0);
    Complexo* c2 = criarComplexo(1.0, 2.0);

    Complexo* soma = somarComplexos(c1, c2);
    Complexo* subtracao = subtrairComplexos(c1, c2);
    Complexo* multiplicacao = multiplicarComplexos(c1, c2);

    printf("Soma: %.2f + %.2fi\n", soma->real, soma->imaginario);
    printf("Subtracao: %.2f + %.2fi\n", subtracao->real, subtracao->imaginario);
    printf("Multiplicacao: %.2f + %.2fi\n", multiplicacao->real, multiplicacao->imaginario);

    liberarComplexo(c1);
    liberarComplexo(c2);
    liberarComplexo(soma);
    liberarComplexo(subtracao);
    liberarComplexo(multiplicacao);

    return 0;
}