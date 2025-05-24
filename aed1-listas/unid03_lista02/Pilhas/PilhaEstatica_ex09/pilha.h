#define MAX 256

// Estrutura da pilha estática
typedef struct {
    char dados[MAX];
    int topo;
} Pilha;

// Funções da pilha
Pilha* criaPilha();
void liberaPilha(Pilha* p);
void inicializaPilha(Pilha* p);
int pilhaVazia(Pilha* p);
int pilhaCheia(Pilha* p);
int empilha(Pilha* p, char c);
char desempilha(Pilha* p);

// Função que verifica se uma frase é palíndromo
int verifica_palindromo(const char* frase);