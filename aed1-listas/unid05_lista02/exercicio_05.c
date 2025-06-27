#include <stdio.h>
#include <string.h>

#define quantidade_animais 10
#define tamanho_nome 30
#define tamanho_raca 15

typedef struct
{
    int id;
    char nome[tamanho_nome];
    char raca[tamanho_raca];
} Animal;

void bubbleSortAnimais(Animal animais[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(animais[j].nome, animais[j+1].nome) > 0) // Compara nomes alfabeticamente
            {
                Animal temp = animais[j];
                animais[j] = animais[j + 1];
                animais[j + 1] = temp;
            }
        }
    }
}

int main()
{
    Animal animais[quantidade_animais] = {
        {101, "Leao", "Mamifero"},
        {102, "Arara", "Ave"},
        {103, "Cobra", "Reptil"},
        {104, "Elefante", "Mamifero"},
        {105, "Zebra", "Mamifero"},
        {106, "Tigre", "Mamifero"},
        {107, "Gato", "Mamifero"},
        {108, "Cachorro", "Mamifero"},
        {109, "Papagaio", "Ave"},
        {110, "Jacare", "Reptil"}};

    int n = 10;

    for (int i = 0; i < n; i++)
    {
        printf("%3d  %-10s  %-10s\n", animais[i].id, animais[i].nome, animais[i].raca);
    }

    bubbleSortAnimais(animais, n);

    printf("\nAnimais ordenados por nome:\n\n");
    for (int i = 0; i < quantidade_animais; i++)
    {
        printf("%3d  %-10s  %-10s\n", animais[i].id, animais[i].nome, animais[i].raca);
    }

    return 0;
}