#include <stdio.h>

int main() {

    int a, b;
    int *ptrA = &a;
    int *ptrB = &b;

    printf("Endereco de a: %p\n", ptrA);
    printf("Endereco de b: %p\n", ptrB);

    printf("\n");
    if (ptrA > ptrB) {
        printf("O maior endereco e: %p (variavel a)\n", ptrA);
    } else {
        printf("O maior endereco e: %p (variavel b)\n", ptrB);
    }

    return 0;
}