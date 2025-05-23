// Questão 03

// Define a estrutura do produto
typedef struct produto{
    int codigo;
    char nomeProd[30];
    float preco;
    int qtdEstoque;
} Produto;

// Define a estrutura da lista
typedef struct elemento* Lista;

// Protótipos
Lista* cria_lista();
void inicializa_lista(Lista* li);
void libera_lista(Lista* li);
int tamanho_lista(Lista* li);

int cadastra_produto(Lista* li, Produto prod);
int remove_lista(Lista* li, int cod);
int busca_lista_menor_preco(Lista* li);
void imprime_lista(Lista* li);

// Questão 02
int consulta_anterior_e_proximo(Lista* li, int cod, Produto* anterior, Produto* proximo);

// Questão 01
int removeNprimeirosProdutos(Lista* li, int n);
int removeNultimosProdutos(Lista* li, int n);