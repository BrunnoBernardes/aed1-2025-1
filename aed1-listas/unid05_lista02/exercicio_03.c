// Código ilustrativo da contagem braçal das trocas e comparações em algoritmos de ordenação
// Feito com GPT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Conta trocas e comparações em vários algoritmos de ordenação

void troca(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n, int *comparacoes, int *trocas)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            (*comparacoes)++;
            if (arr[j] > arr[j + 1])
            {
                troca(&arr[j], &arr[j + 1]);
                (*trocas)++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int *comparacoes, int *trocas)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            (*comparacoes)++;
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            troca(&arr[i], &arr[minIndex]);
            (*trocas)++;
        }
    }
}

void mergeSort(int arr[], int left, int right, int *comparacoes, int *trocas)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, comparacoes, trocas);
        mergeSort(arr, mid + 1, right, comparacoes, trocas);

        int i = left, j = mid + 1, k = 0;
        int len = right - left + 1;
        int *temp = malloc(len * sizeof(int));

        while (i <= mid && j <= right)
        {
            (*comparacoes)++;
            if (arr[i] <= arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
            }
        }
        while (i <= mid)
            temp[k++] = arr[i++];
        while (j <= right)
            temp[k++] = arr[j++];

        for (i = left, k = 0; i <= right; i++, k++)
        {
            arr[i] = temp[k];
        }
        free(temp);
    }
}

void quickSort(int arr[], int low, int high, int *comparacoes, int *trocas)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            (*comparacoes)++;
            if (arr[j] < pivot)
            {
                i++;
                troca(&arr[i], &arr[j]);
                (*trocas)++;
            }
        }
        troca(&arr[i + 1], &arr[high]);
        (*trocas)++;
        int pi = i + 1;
        quickSort(arr, low, pi - 1, comparacoes, trocas);
        quickSort(arr, pi + 1, high, comparacoes, trocas);
    }
}

void imprimeVetor(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int vetorA[6] = {21, 19, 17, 9, 5, 1};
    int vetorB[12] = {2, 4, 6, 8, 10, 12, 11, 9, 7, 5, 3, 1};
    int vetorC[10] = {18, 29, 17, 29, 23, 21, 23, 8, 14, 6};

    int vetorTemp[12];
    int comparacoes, trocas;

    // Bubble Sort
    memcpy(vetorTemp, vetorA, 6 * sizeof(int));
    comparacoes = 0;
    trocas = 0;
    bubbleSort(vetorTemp, 6, &comparacoes, &trocas);
    printf("Bubble Sort   - A: %d comps, %d swaps | ", comparacoes, trocas);
    imprimeVetor(vetorTemp, 6);

    memcpy(vetorTemp, vetorB, 12 * sizeof(int));
    comparacoes = 0;
    trocas = 0;
    bubbleSort(vetorTemp, 12, &comparacoes, &trocas);
    printf("Bubble Sort   - B: %d comps, %d swaps | ", comparacoes, trocas);
    imprimeVetor(vetorTemp, 12);

    memcpy(vetorTemp, vetorC, 10 * sizeof(int));
    comparacoes = 0;
    trocas = 0;
    bubbleSort(vetorTemp, 10, &comparacoes, &trocas);
    printf("Bubble Sort   - C: %d comps, %d swaps | ", comparacoes, trocas);
    imprimeVetor(vetorTemp, 10);

    // Selection Sort
    memcpy(vetorTemp, vetorA, 6 * sizeof(int));
    comparacoes = 0;
    trocas = 0;
    selectionSort(vetorTemp, 6, &comparacoes, &trocas);
    printf("Selection Sort- A: %d comps, %d swaps | ", comparacoes, trocas);
    imprimeVetor(vetorTemp, 6);

    memcpy(vetorTemp, vetorB, 12 * sizeof(int));
    comparacoes = 0;
    trocas = 0;
    selectionSort(vetorTemp, 12, &comparacoes, &trocas);
    printf("Selection Sort- B: %d comps, %d swaps | ", comparacoes, trocas);
    imprimeVetor(vetorTemp, 12);

    memcpy(vetorTemp, vetorC, 10 * sizeof(int));
    comparacoes = 0;
    trocas = 0;
    selectionSort(vetorTemp, 10, &comparacoes, &trocas);
    printf("Selection Sort- C: %d comps, %d swaps | ", comparacoes, trocas);
    imprimeVetor(vetorTemp, 10);

    // Merge Sort
    memcpy(vetorTemp, vetorA, 6 * sizeof(int));
    comparacoes = 0;
    trocas = 0;
    mergeSort(vetorTemp, 0, 5, &comparacoes, &trocas);
    printf("Merge Sort    - A: %d comps, %d swaps | ", comparacoes, trocas);
    imprimeVetor(vetorTemp, 6);

    memcpy(vetorTemp, vetorB, 12 * sizeof(int));
    comparacoes = 0;
    trocas = 0;
    mergeSort(vetorTemp, 0, 11, &comparacoes, &trocas);
    printf("Merge Sort    - B: %d comps, %d swaps | ", comparacoes, trocas);
    imprimeVetor(vetorTemp, 12);

    memcpy(vetorTemp, vetorC, 10 * sizeof(int));
    comparacoes = 0;
    trocas = 0;
    mergeSort(vetorTemp, 0, 9, &comparacoes, &trocas);
    printf("Merge Sort    - C: %d comps, %d swaps | ", comparacoes, trocas);
    imprimeVetor(vetorTemp, 10);

    // Quick Sort
    memcpy(vetorTemp, vetorA, 6 * sizeof(int));
    comparacoes = 0;
    trocas = 0;
    quickSort(vetorTemp, 0, 5, &comparacoes, &trocas);
    printf("Quick Sort    - A: %d comps, %d swaps | ", comparacoes, trocas);
    imprimeVetor(vetorTemp, 6);

    memcpy(vetorTemp, vetorB, 12 * sizeof(int));
    comparacoes = 0;
    trocas = 0;
    quickSort(vetorTemp, 0, 11, &comparacoes, &trocas);
    printf("Quick Sort    - B: %d comps, %d swaps | ", comparacoes, trocas);
    imprimeVetor(vetorTemp, 12);

    memcpy(vetorTemp, vetorC, 10 * sizeof(int));
    comparacoes = 0;
    trocas = 0;
    quickSort(vetorTemp, 0, 9, &comparacoes, &trocas);
    printf("Quick Sort    - C: %d comps, %d swaps | ", comparacoes, trocas);
    imprimeVetor(vetorTemp, 10);

    return 0;
}
