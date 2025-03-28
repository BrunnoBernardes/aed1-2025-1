// Define a estrutura do cubo
typedef struct {
    float lado;
} Cubo;

// Cria um cubo com o lado especificado
Cubo* criarCubo(float lado);

// Retorna o lado do cubo
float obterLado(Cubo* c);

// Calcula a área superficial do cubo
float calcularArea(Cubo* c);

// Calcula o volume do cubo
float calcularVolume(Cubo* c);

// Libera a memória alocada para o cubo
void liberarCubo(Cubo* c);