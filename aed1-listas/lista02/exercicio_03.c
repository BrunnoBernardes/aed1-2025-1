#include <stdio.h>
#include <math.h>

// Define a estrutura Ponto
typedef struct {
    double x;
    double y;
} Ponto;

int main (){

    Ponto ponto;
    double distancia_origem;

    printf("Digite as coordenadas do ponto: ");
    scanf("%lf %lf", &ponto.x, &ponto.y);

    // Calcula a distância entre o ponto e a origem usando a fórmula: 𝑑𝐴𝐵²  =   (𝑥𝐵 – 𝑥𝐴)²  +  (𝑦𝐵 – 𝑦𝐴)²
    distancia_origem = sqrt(ponto.x * ponto.x + ponto.y * ponto.y);
    printf("A distancia do ponto para a origem e: %.2lf\n", distancia_origem);

    return 0;
}