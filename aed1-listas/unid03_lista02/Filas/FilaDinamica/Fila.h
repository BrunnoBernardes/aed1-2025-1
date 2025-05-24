#define MAX 50
typedef struct cliente {
    int codigo;
    char nome[MAX];
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

// Protótipos
Fila* criaFila();
void liberaFila(Fila* f);
void inicializaFila(Fila* f);
int insereFila(Fila* f, Cliente c);
int removeFila(Fila* f, Cliente* c);
void listarFila(Fila* f);
int tamanhoFila(Fila* f);
float tempoMedioEspera(Fila* f);