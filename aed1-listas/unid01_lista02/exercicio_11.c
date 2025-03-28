#include <stdio.h>

int main (){

    int vetor[5] = {100, 200, 300, 400, 500};
    int *ptr = vetor;
    int i;

    for (i = 0; i < 5; i++){
        *(ptr + i) /= 10;
    }

    for (i = 0; i < 5; i++){
        printf("%d\n", *(ptr + i));
    }

    printf("\n");
    return 0;
}