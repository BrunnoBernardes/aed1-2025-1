#include <stdio.h>

int main() {

    int a, b;

    printf("Digite o valor de a: ");
    scanf("%d", &a);
    printf("Digite o valor de b: ");
    scanf("%d", &b);

    int *ptr_a = &a;
    int *ptr_b = &b;

    printf("\n");
    printf("Endereco de a: %p\n", ptr_a);
    printf("Endereco de b: %p\n", ptr_b);

    printf("\n");
    if (ptr_a > ptr_b) {
        printf("O  conteudo do maior endereco e: %d", *ptr_a);
    } else {
        printf("O  conteudo do maior endereco e: %d", *ptr_b);
    }

    return 0;
}
