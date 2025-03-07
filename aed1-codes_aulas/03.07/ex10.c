#include <stdio.h>

typedef struct {
    char nome[50];
    int matricula;
    int anos_trabalhados;
    char departamento[50];
} Funcionario;

void pode_aposentar(Funcionario funcionario) {
    if (funcionario.anos_trabalhados >= 30) {
        printf("O funcionario %s (%d) pode aposentar!\n", funcionario.nome, funcionario.matricula);
    } else {
        printf("O funcionario %s (%d) nao pode aposentar!\n", funcionario.nome, funcionario.matricula);
    }
}

int main() {

    Funcionario funcionario;
    int numero_funcionarios;
    int i;

    printf("Digite o numero de funcionarios: ");
    scanf("%d", &numero_funcionarios);

    for (i = 0; i < numero_funcionarios; i++) {
        printf("Digite o nome, matricula, anos trabalhados e departamento do funcionario:\n");
        scanf("%*c%[^\n] %d %d %s", funcionario.nome, &funcionario.matricula, &funcionario.anos_trabalhados, funcionario.departamento);
        printf("Nome: %s\nMatricula: %d\nAnos trabalhados: %d\nDepartamento: %s\n", funcionario.nome, funcionario.matricula, funcionario.anos_trabalhados, funcionario.departamento);
    }

    for (i = 0; i < numero_funcionarios; i++) {
        pode_aposentar(funcionario[i]);
    }

    return 0;
}