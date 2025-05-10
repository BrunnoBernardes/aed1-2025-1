/*
    Dupla:
    Brunno Bernardes - 202405846
    Lourenço Tabosa - 202401799
*/

//Arquivo ListaMedica.h

typedef struct medico {
    char nome[30];
    int id_medico;
} Medico;

typedef struct paciente {
    char nome[30];
    int cod_paciente;
    int cid_id;
    char cid_nome[30];
    bool situacao_vida;
    int id_medico;
    Medico medico;
} Paciente;

typedef struct no No;
typedef struct lista Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_final(Lista* li, Paciente p);
int insere_lista_inicio(Lista* li, Paciente p);
int insere_lista_ordenada(Lista* li, Paciente p);
int remove_lista(Lista* li, int cod);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int consulta_lista_cod(Lista* li, int cod);
void imprime_lista(Lista* li);