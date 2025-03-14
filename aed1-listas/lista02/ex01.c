#include <stdio.h>
#include <string.h>

typedef struct {
    char logradouro[50];
    int numero;
    char bairro[50];
    char complemento[50];
    char cidade[50];
    char estado[50];
    char cep[10];
} Endereco;

typedef struct {
    char nome[50];
    int idade;
    Endereco endereco;
} Pessoa;

int main (){

    Pessoa p;

    // Ler os dados da pessoa
    // Nome
    printf("Digite o nome completo: ");
    fgets(p.nome, 50, stdin);
    if (p.nome[strlen(p.nome) - 1] == '\n') {
        p.nome[strlen(p.nome) - 1] = '\0';
    }
    printf("Digite a idade: ");
    
    // Idade
    scanf("%d", &p.idade);
    while (p.idade < 0 || p.idade > 120) {
        printf("Idade invalida\n");
        printf("Digite a idade: ");
        scanf("%d", &p.idade);
    }
    getchar();

    // Endereço
    printf("Digite o logradouro: ");
    fgets(p.endereco.logradouro, 50, stdin);
    if (p.endereco.logradouro[strlen(p.endereco.logradouro) - 1] == '\n') {
        p.endereco.logradouro[strlen(p.endereco.logradouro) - 1] = '\0';
    }

    // Número
    printf("Digite o numero: ");
    scanf("%d", &p.endereco.numero);
    getchar();

    // Bairro
    printf("Digite o bairro: ");
    fgets(p.endereco.bairro, 50, stdin);
    if (p.endereco.bairro[strlen(p.endereco.bairro) - 1] == '\n') {
        p.endereco.bairro[strlen(p.endereco.bairro) - 1] = '\0';
    }

    // Complemento
    printf("Digite o complemento: ");
    fgets(p.endereco.complemento, 50, stdin);
    if (p.endereco.complemento[strlen(p.endereco.complemento) - 1] == '\n') {
        p.endereco.complemento[strlen(p.endereco.complemento) - 1] = '\0';
    }

    // Cidade
    printf("Digite a cidade: ");
    fgets(p.endereco.cidade, 50, stdin);
    if (p.endereco.cidade[strlen(p.endereco.cidade) - 1] == '\n') {
        p.endereco.cidade[strlen(p.endereco.cidade) - 1] = '\0';
    }

    // Estado
    printf("Digite o estado: ");
    fgets(p.endereco.estado, 50, stdin);
    if (p.endereco.estado[strlen(p.endereco.estado) - 1] == '\n') {
        p.endereco.estado[strlen(p.endereco.estado) - 1] = '\0';
    }

    // CEP
    printf("Digite o cep: ");
    scanf("%s", p.endereco.cep);

    // Exibir os dados da pessoa
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Logradouro: %s\n", p.endereco.logradouro);
    printf("Numero: %d\n", p.endereco.numero);
    printf("Bairro: %s\n", p.endereco.bairro);
    printf("Complemento: %s\n", p.endereco.complemento);
    printf("Cidade: %s\n", p.endereco.cidade);
    printf("Estado: %s\n", p.endereco.estado);
    printf("Cep: %s\n", p.endereco.cep);

    return 0;
}