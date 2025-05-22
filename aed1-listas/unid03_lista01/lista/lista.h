#define MAX 100

// Definição da estrutura Lista
typedef struct lista Lista;

// Prtótipos
Lista* criaLista();
void liberaLista(Lista* l);
int tamanhoLista(Lista* l);
int listaVazia(Lista* l);
int listaCheia(Lista* l);
int insereInicio(Lista* l, int elem);
int insereFim(Lista* l, int elem);
int insereOrdenado(Lista* l, int elem);
int removeInicio(Lista* l);
int removeFim(Lista* l);
int removeElemento(Lista* l, int elem);
int consultaValor(Lista* l, int elem, int* pos);
int consultaIndice(Lista* l, int indice, int* elem);
void imprimeLista(Lista* l);