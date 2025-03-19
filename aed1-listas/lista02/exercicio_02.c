#include <stdio.h>
#include <math.h>

// Define a estrutura Ponto
typedef struct {
    double x;
    double y;
} Ponto;

int main (){

    Ponto p1, p2;
    double distancia;

    printf("Digite as coordenadas do ponto 1: ");
    scanf("%lf %lf", &p1.x, &p1.y);

    printf("Digite as coordenadas do ponto 2: ");
    scanf("%lf %lf", &p2.x, &p2.y);

    // Calcula a distância entre os dois pontos usando a fórmula: 𝑑𝐴𝐵²  =   (𝑥𝐵 – 𝑥𝐴)²  +  (𝑦𝐵 – 𝑦𝐴)²
    distancia = sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
    printf("A distancia entre os dois pontos e: %.2lf\n", distancia);

    return 0;
}