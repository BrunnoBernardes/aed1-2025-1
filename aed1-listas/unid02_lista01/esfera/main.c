#include "esfera.h"

int main() {
    Esfera* minhaEsfera = criarEsfera(6.0);

    printf("Raio: %.2f\n", obterRaio(minhaEsfera));
    printf("Area: %.2f\n", calcularArea(minhaEsfera));
    printf("Volume: %.2f\n", calcularVolume(minhaEsfera));

    liberarEsfera(minhaEsfera);
    return 0;
}