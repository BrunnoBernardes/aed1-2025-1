#define MAX 100

// Definição da estrutura do elemento da fila de prioridade
typedef struct elemento {
    int prioridade; // Prioridade do elemento ascendente (0 é a maior prioridade)
    int dado;
} Elemento;

// Definição da estrutura da fila de prioridade
typedef struct fila_prioridade FilaPrio;

// Protótipos
FilaPrio* criaFila();
void inicializaFila(FilaPrio* f);
void liberaFila(FilaPrio* f);
int tamanhoFila(FilaPrio* f);
int filaVazia(FilaPrio* f);
int filaCheia(FilaPrio* f);
int insereFila(FilaPrio* f, Elemento elem);
int removeFila(FilaPrio* f);
int consultaFila(FilaPrio* f, Elemento* elem);
void imprimeFila(FilaPrio* f);