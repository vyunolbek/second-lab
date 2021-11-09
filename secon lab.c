#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const double RAND_MAX_F = RAND_MAX;

void bubbleSort(double* arrbs, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - (i + 1); j++)
        {
            if (arrbs[j] > arrbs[j + 1])
            {
                double buff = arrbs[j];
                arrbs[j] = arrbs[j + 1];
                arrbs[j + 1] = buff;
            }
        }
    }
}

void quickSort(double* mas, int start, int end)
{
    int left = start;
    int right = end;
    double pivot = mas[(left + right) / 2];
    while (left <= right)
    {
        while (mas[left] < pivot)
        {
            left++;
        }
        while (mas[right] > pivot)
        {
            right--;
        }
        if (left <= right)
        {
            double buff = mas[left];
            mas[left] = mas[right];
            mas[right] = buff;
            left++;
            right--;
        }
    }
    if (start < right)
        quickSort(mas, start, right);
    if (end > left)
        quickSort(mas, left, end);
}

void insertionSort(double* mas, int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j > 0 && mas[j - 1] > mas[j]; j--)
        {
            double buff = mas[j];
            mas[j] = mas[j - 1];
            mas[j - 1] = buff;
        }
    }
}

int main()
{
    srand(time(NULL));
    FILE* file = fopen("file.txt", "w");
    int size;
    double startTime, endTime;
    printf("Введите кол-во элементов в массиве: ");
    scanf_s("%d", &size);
    file = fopen("../first prog/file.txt", "r");

    double* b, * a;

    a = (double*)malloc(size * sizeof(double));
    b = (double*)malloc(size * sizeof(double));

    for (int i = 0; i < size; i++)
    {
        fscanf(file, "%lf", a + i);
    }

    memcpy(b, a, sizeof(double) * size);

    // Bubble Sort

    startTime = clock();
    bubbleSort(b, size);
    endTime = clock();
    printf("\nrun time %lf\n", (endTime - startTime) / 1000);
    printf("bubblesort is complete\n");
    memcpy(b, a, sizeof(double) * size);

    // Quick sort

    startTime = clock();
    quickSort(b, 0, size - 1);
    endTime = clock();
    printf("\nrun time %lf\n", (endTime - startTime) / 1000);
    printf("quick sort is complete\n");
    memcpy(b, a, sizeof(double) * size);

    // Insertion sort

    startTime = clock();
    insertionSort(b, size);
    endTime = clock();
    printf("\nrun time %lf\n", (endTime - startTime) / 1000);
    printf("insertion sort is complete\n");
}