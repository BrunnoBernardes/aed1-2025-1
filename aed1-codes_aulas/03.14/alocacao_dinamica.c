#include <stdio.h>
#include <stdlib.h>

int main (){

    int *p;
    p = (int *) malloc(sizeof(int));
    if (p == NULL) {
        printf("Erro de alocação de memória\n");
        return 1;
    }
    int i;
    for (i = 0; i < 10; i++) {
        printf("Digite o valor da posição %d: ", i);
        scanf("%d", &p[i]);
    }

    system("pause");
    return 0;
}