#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int resolvidos;
} Aluno;

Aluno *criaLista(int n) {
    Aluno *l = (Aluno *)malloc(n * sizeof(Aluno));
    if (l == NULL) {
        printf("Erro ao alocar memoria para a lista.\n");
        exit(1);
    }
    return l;
}

void inicializaLista(Aluno *l, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%49s %d", l[i].nome, &l[i].resolvidos);
    }
}

void selectionSortDecrescente(Aluno *l, int n) {
    for (int i = 0; i < n - 1; i++) {
        int index = i;
        for (int j = i + 1; j < n; j++) {
            if (l[j].resolvidos > l[index].resolvidos ||
               (l[j].resolvidos == l[index].resolvidos && strcmp(l[j].nome, l[index].nome) < 0)) {
                index = j;
            }
        }
        if (index != i) {
            Aluno temp = l[i];
            l[i] = l[index];
            l[index] = temp;
        }
    }
}

void imprimeLista(Aluno *l, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %d", l[i].nome, l[i].resolvidos);
        if (i == n - 1) {
            printf(" #reprovado(a)");
        }
        printf("\n");
    }
}

void liberaLista(Aluno *l) {
    if (l != NULL) {
        free(l);
    }
}

int main () {
    
    int n;
    scanf("%d", &n);
    if (n < 1 || n > 100) return 0;
    
    Aluno *alunos = criaLista(n);
    inicializaLista(alunos, n);

    selectionSortDecrescente(alunos, n);

    imprimeLista(alunos, n);
    liberaLista(alunos);

    return 0;
}