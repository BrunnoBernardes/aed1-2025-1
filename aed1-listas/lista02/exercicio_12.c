#include <stdio.h>

int main (){

    int var, *ptr1, **ptr2, ***ptr3;

    printf("Digite um valor inteiro: ");
    scanf("%d", &var);

    ptr1 = &var;
    ptr2 = &ptr1;
    ptr3 = &ptr2;

    printf("\n");

    // Valor de var
    printf("Valor de var: %d\n", var);

    // Valor de var dobrado
    *(ptr1) *= 2;
    printf("Valor de var: %d\n", *ptr1);
    
    // Valor de var triplicado
    **(ptr2) *= 3;
    printf("Valor de var: %d\n", **ptr2);
    
    // Valor de var quadruplicado
    ***(ptr3) *= 4;
    printf("Valor de var: %d\n", ***ptr3);

    printf("\n");

    return 0;
}