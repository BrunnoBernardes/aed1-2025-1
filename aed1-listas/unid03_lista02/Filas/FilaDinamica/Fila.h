typedef struct cliente {
    int codigo;
    char nome[50];
} Cliente;

typedef struct no {
    Cliente dados;
    struct no* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
    int tamanho;
} Fila;

// Operações
Fila* criaFila();
void liberaFila(Fila* f);
int enfileira(Fila* f, Cliente c);
int desenfileira(Fila* f, Cliente* c);
void listarFila(Fila* f);
int tamanhoFila(Fila* f);
float tempoMedioEspera(Fila* f);