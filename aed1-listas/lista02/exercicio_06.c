#include <stdio.h>

typedef struct {
    char nome[50]; // 50 bytes
    // + 2 bytes de padding
    int matricula; // 4 bytes
    int prova01; // 4 bytes
    int prova02; // 4 bytes
    int prova03; // 4 bytes
} Aluno; // 66 bytes

int main (){

    int tamanho_struct = sizeof(Aluno);
    printf("Tamanho da estrutura Aluno em bytes: %d\n", tamanho_struct);

    return 0;
}