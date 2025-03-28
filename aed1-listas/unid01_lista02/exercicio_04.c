#include <stdio.h>
#include <string.h>

#define MAX 50

typedef struct {
    char nome[MAX];
    char cargo[MAX];
    double salario_base;
    double salario_total;
    char cpf[12];
    char departamento[MAX];
} Funcionario;

int main (){

    int n_funcionarios;
    printf("Digite o numero de funcionarios: ");
    scanf("%d", &n_funcionarios);

    Funcionario funcionarios[n_funcionarios];

    int i;
    for (i = 0; i < n_funcionarios; i++){
        printf("Digite o nome completo do funcionario %d: ", i+1);
        scanf("%*c%[^\n]", funcionarios[i].nome);
        
        while (1){
            printf("Digite o CPF do funcionario %d: ", i+1);
            scanf("%*c%[^\n]", funcionarios[i].cpf);
            if (strlen(funcionarios[i].cpf) == 11) {
                break; // CPF válido
            } else {
                printf("CPF invalido. Digite um CPF com 11 digitos.\n");
            }
        }
        printf("Digite o cargo do funcionario (Assistente, Supervisor, Gerente, etc) %d: ", i+1);
        scanf("%*c%[^\n]", funcionarios[i].cargo);
        printf("Digite o departamento do funcionario %d: ", i+1);
        scanf("%*c%[^\n]", funcionarios[i].departamento);
        printf("Digite o salario base do funcionario %d: ", i+1);
        scanf("%lf", &funcionarios[i].salario_base);

        // Calcula o salario total do funcionario pelo cargo
        if (strcmp(funcionarios[i].cargo, "Assistente") == 0) {
            funcionarios[i].salario_total = funcionarios[i].salario_base * 1.05;
        } else if (strcmp(funcionarios[i].cargo, "Supervisor") == 0) {
            funcionarios[i].salario_total = funcionarios[i].salario_base * 1.1;
        } else if (strcmp(funcionarios[i].cargo, "Gerente") == 0) {
            funcionarios[i].salario_total = funcionarios[i].salario_base * 1.15;
        } else {
            funcionarios[i].salario_total = funcionarios[i].salario_base * 1.02;
        }

    }

    printf("\n\n");

    printf("| NOME | CPF | CARGO | DEPARTAMENTO | SALARIO BASE | SALARIO TOTAL |\n");

    for (i = 0; i < n_funcionarios; i++){
        printf("| %s ", funcionarios[i].nome);
        printf("| %s ", funcionarios[i].cpf);
        printf("| %s ", funcionarios[i].cargo);
        printf("| %s ", funcionarios[i].departamento);
        printf("| R$%.2lf ", funcionarios[i].salario_base);
        printf("| R$%.2lf |", funcionarios[i].salario_total);
        printf("\n");
    }

    return 0;
}