#include "cilindro.h"

int main() {
    Cilindro* meuCilindro = criarCilindro(5.0, 10.0);

    printf("Raio: %.2f\n", obterRaio(meuCilindro));
    printf("Altura: %.2f\n", obterAltura(meuCilindro));
    printf("Area: %.2f\n", calcularArea(meuCilindro));
    printf("Volume: %.2f\n", calcularVolume(meuCilindro));
    
    liberarCilindro(meuCilindro);
    return 0;
}