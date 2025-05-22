#define TAM 20

// Definição da estrutura da pilha
typedef struct pilha Pilha;

// A pilha é implementada como um vetor de inteiros
Pilha *cria_pilha();

// Função para inicializar a pilha
void inicializa_pilha(Pilha *stack);

// Função para liberar a pilha
void libera_pilha(Pilha *stack);

// Função para verificar o tamanho da pilha
int tamanho_pilha(Pilha *stack);

// Função para verificar se a pilha está cheia
int pilha_cheia(Pilha *stack);

// Função para verificar se a pilha está vazia
int pilha_vazia(Pilha *stack);

// Função para inserir um elemento na pilha
int insere_pilha(Pilha *stack, int elem);

// Função para remover um elemento da pilha
int remove_pilha(Pilha *stack);

// Função para consultar o elemento do topo da pilha
int consulta_topo(Pilha *stack);

// Função para imprimir os elementos da pilha
void imprime_pilha(Pilha *stack);