#define MAX 50

// Estrutura do nó da pilha
typedef struct no {
    char dado;
    struct no* prox;
} No;

typedef struct pilha {
    No* topo;
} Pilha;

// Protótipos das funções
Pilha* criapilha();
void liberaPilha(Pilha* pilha);
int tamanhoPilha(Pilha* pilha);
int pilhaVazia(Pilha* pilha);
int inserirPilha(Pilha* pilha, char valor);
int removerPilha(Pilha* pilha, char* valor);
int verifica_parentizacao(const char* expr);
