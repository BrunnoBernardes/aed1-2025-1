#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

int main () {
    int tam = 3;
    Paciente vet_paciente[tam];
    Pilha* stack;

    printf("Preencha os dados dos %d pacientes: ", tam);
    int i;
    for (i = 0; i < tam; i++){
        printf("Insira o codigo do paciente");
        scanf("%d", &vet_paciente[i].code_person);
        printf("Insira o primeiro nome do paciente");
        scanf("%s", &vet_paciente[i].nome);
        printf("Insira a idade do paciente");
        scanf("%d", &vet_paciente[i].idade);
        printf("Insira o codigo da doenca");
        scanf("%d", &vet_paciente[i].code_cid);
        printf("Insira o sexo do paciente");
        scanf("%c", &vet_paciente[i].sex);
    }

    
}