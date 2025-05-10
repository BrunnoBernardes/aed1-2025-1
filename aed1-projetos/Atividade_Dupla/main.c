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

    Paciente p1 = {"João", 101, 1, "A00", true, 501, {"Dr. Marcos", 501}};
    Paciente p2 = {"Maria", 102, 2, "B01", false, 502, {"Dra. Ana", 502}};
    Paciente p3 = {"Carlos", 100, 3, "C02", true, 503, {"Dr. Pedro", 503}};

    insere_lista_ordenada(lista, p1);
    insere_lista_ordenada(lista, p2);
    insere_lista_ordenada(lista, p3);

    imprime_lista(lista);

    printf("\nConsulta:\n");
    consulta_lista_cod(lista, 102);

    libera_lista(lista);
    return 0;
}
