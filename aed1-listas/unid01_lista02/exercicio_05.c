#include <stdio.h>

int main() {

    int tamanho_char = sizeof(char);
    int tamanho_int = sizeof(int);
    int tamanho_float = sizeof(float);
    int tamanho_double = sizeof(double);

    printf("Tamanho dos tipos de dados em bytes:\n");

    printf("char: %d byte(s)\n", tamanho_char);
    printf("int: %d byte(s)\n", tamanho_int);
    printf("float: %d byte(s)\n", tamanho_float);
    printf("double: %d byte(s)\n", tamanho_double);

    return 0;
}
