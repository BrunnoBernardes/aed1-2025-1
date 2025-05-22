#define MAX 100

// Definição da estrutura da fila
typedef struct fila Fila;

// Protótipos
Fila* criaFila();
void inicializaFila(Fila* f);
void liberaFila(Fila* f);
int tamanhoFila(Fila* f);
int filaVazia(Fila* f);
int filaCheia(Fila* f);
int insereFila(Fila* f, int elem);
int removeFila(Fila* f);
int consultaFila(Fila* f);
void imprimeFila(Fila* f);