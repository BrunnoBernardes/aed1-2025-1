#define MAX_STK 100

typedef struct paciente {
    int code_person;
    char nome[51];
    int idade;
    int code_cid;
    char sex;
} Paciente;

typedef struct pilha Pilha;