// Questão 05
#define MAX 100

typedef struct fila Fila;

// Protótipos
Fila* cria_Fila();
void libera_Fila(Fila* fi);
void inicializa_Fila(Fila* fi);
int insere_Fila(Fila* fi, int elemento);
int copia_Fila(Fila* fi, Fila* fi2);
void imprime_Fila(Fila* fi);

// Questão 06
int intercala_Filas(Fila* fi, Fila* fi2, Fila* fi3);
int remove_Fila(Fila* fi);

