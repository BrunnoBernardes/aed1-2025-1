#include <stdio.h>
#include "cubo.h"

int main() {
    Cubo* meuCubo = criarCubo(5.0);

    printf("Lado: %.2f\n", obterLado(meuCubo));
    printf("Area: %.2f\n", calcularArea(meuCubo));
    printf("Volume: %.2f\n", calcularVolume(meuCubo));

    liberarCubo(meuCubo);
    return 0;
}