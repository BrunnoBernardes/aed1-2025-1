#define MAX 100

// Definição da estrutura Lista
typedef struct lista Lista;

// Prtótipos
Lista* criaLista();
void inicializaLista(Lista* l);
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
int consultaValor(Lista* l, int elem, int* index);
int consultaIndice(Lista* l, int index, int* elem);
void imprimeLista(Lista* l);

// Questão 01
int removeNPrimeirosElementos(Lista* l, int n);
int removeNUltimosElementos(Lista* l, int n);

// Questão 04
int quantidadePares(Lista* l);
int mediaLista(Lista* l);
int maiorValor(Lista* l);
int menorValor(Lista* l);
int posicaoMaiorValor(Lista* l);
int posicaoMenorValor(Lista* l);
int somaLista(Lista* l);
int numeroNosImpares(Lista* l);