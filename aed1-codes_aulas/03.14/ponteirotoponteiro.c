#include <stdio.h>

int main (){

    char letra = 'a';
    char *p = &letra;
    char **pp = &p;
    char ***ppp = &pp;
    char ****pppp = &ppp;

    printf("letra = %c\n", letra);
    printf("endereco de letra = %p\n", &letra);
    printf("*p = %c\n", *p);
    printf("endereco de p = %p\n", p);
    printf("**pp = %c\n", **pp);
    printf("endereco de pp = %p\n", pp);
    printf("***ppp = %c\n", ***ppp);
    printf("endereco de ppp = %p\n", ppp);
    printf("****pppp = %c\n", ****pppp);
    printf("endereco de pppp = %p\n", pppp);

    //system("pause");

    return 0;
}