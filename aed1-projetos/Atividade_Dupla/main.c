/*
    Dupla:
    Brunno Bernardes - 202405846
    Lourenço Tabosa - 202401799
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ListaMedica.h"

int main() {
    Lista* lista = cria_lista();

    Paciente p1 = {"João Silva", 1001, 10, "A00.0", true, 501, {"Dr. Marcos", 501}};
    Paciente p2 = {"Maria Souza", 1002, 11, "B01.1", false, 502, {"Dra. Ana", 502}};
    Paciente p3 = {"Carlos Lima", 1000, 12, "C02.1", true, 503, {"Dr. Pedro", 503}};
    Paciente p4 = {"Ana Clara", 1003, 13, "K51.0", true, 504, {"Dra. Luiza", 504}};

    insere_lista_ordenada(lista, p1);
    insere_lista_ordenada(lista, p2);
    insere_lista_ordenada(lista, p3);
    insere_lista_ordenada(lista, p4);
    
    printf("Lista completa de pacientes:\n");
    imprime_lista(lista);

    printf("\nConsulta do paciente com código 1002:\n");
    consulta_lista_cod(lista, 1002);

    printf("\nRemovendo paciente com código 1003...\n");
    consulta_lista_cod(lista, 1003);

    printf("\nRemovendo o primeiro da lista...\n");
    remove_lista_inicio(lista);
    imprime_lista(lista);

    libera_lista(lista);
    return 0;
}
