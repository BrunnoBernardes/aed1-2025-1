#include <stdio.h>

typedef struct {
    char nome[50];
    int matricula;
    int anos_trabalhados;
    char departamento[50];
} Funcionario;

void pode_aposentar(Funcionario funcionario) {

    printf("\n");

    if (funcionario.anos_trabalhados >= 30) {
        printf("O funcionario %s (%d) pode aposentar!\n", funcionario.nome, funcionario.matricula);
    } else {
        printf("O funcionario %s (%d) nao pode aposentar!\n", funcionario.nome, funcionario.matricula);
    }
}

int main() {

    int numero_funcionarios;
    int i;

    printf("Digite o numero de funcionarios: ");
    scanf("%d", &numero_funcionarios);

    Funcionario funcionario[numero_funcionarios];

    for (i = 0; i < numero_funcionarios; i++) {
        printf("\n");
        printf("Digite o nome, matricula, anos trabalhados e departamento do funcionario:\n");
        getchar();
        scanf("%[^\n] %d %d %s", funcionario[i].nome, &funcionario[i].matricula, &funcionario[i].anos_trabalhados, funcionario[i].departamento);
        printf("\n");
        printf("Nome: %s\nMatricula: %d\nAnos trabalhados: %d\nDepartamento: %s\n", funcionario[i].nome, funcionario[i].matricula, funcionario[i].anos_trabalhados, funcionario[i].departamento);
    }

    for (i = 0; i < numero_funcionarios; i++) {
        pode_aposentar(funcionario[i]);
    }

    printf("\n");

    return 0;
}