#define MAX 100

// Fila FIFO (First In First Out) em C
typedef struct {
    int dados[MAX];
    int inicio, fim, qtd;
} Fila;

// Funções para manipulação da fila
Fila* criaFila();
void liberaFila(Fila* f);
int tamanhoFila(Fila* f);
int filaVazia(Fila* f);
int filaCheia(Fila* f);
int insereFila(Fila* f, int elem);
int removeFila(Fila* f);
int consultaFila(Fila* f, int* elem);
void imprimeFila(Fila* f);