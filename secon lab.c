#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const double RAND_MAX_F = RAND_MAX;

int stringCount(FILE* strC) {
    int result = 0;
    while (!ferror(strC) && !feof(strC)) {
        if (fgetc(strC) == '\n')
            ++result;
    }
    rewind(strC);
    return result;
}

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
    FILE* file = fopen("../first prog/file.txt", "r");
    int size, checkbox = 0, sortCheck = 0;
    double startTime, endTime;
    size = stringCount(file);
    double* b, * a;

    a = (double*)malloc(size * sizeof(double));
    b = (double*)malloc(size * sizeof(double));

    for (int i = 0; i < size; i++)
        fscanf(file, "%lf", &a[i]);

    memcpy(b, a, sizeof(double) * size);

    do
    {
        printf("Выберите нужное действие:\n1. Печать\n2. Сортировка\n3. Сброс\n4. Выход\nВыбор:");
        do
        {
            scanf("%d", &checkbox);
            if (checkbox < 1 || checkbox > 4)
            {
                printf("\nВы неверно ввели номер. Введите снова\n\nВыбор:");
            }
        } while (checkbox < 1 || checkbox > 4);

        if (checkbox == 1)
        {
            for (int i = 0; i < size; i++)
                printf("a[%d] = %lf\n", i, a[i]);
            printf("\n");
        }

        else if (checkbox == 2)
        {
            printf("\nВыберите сортировку:\n1. Пузырьком\n2. Вставками\n3. Быстрая\nВыбор:");
            do
            {
                scanf("%d", &sortCheck);
                if (sortCheck < 1 || sortCheck > 3)
                    printf("\nВы неверно ввели номер. Введите снова\n\nВыбор:");
            } while (sortCheck < 1 || sortCheck > 3);

            if (sortCheck == 1)
            {
                startTime = clock();
                bubbleSort(b, size);
                endTime = clock();
                printf("\nВремя выполнения %lf\n", (endTime - startTime) / 1000);
                printf("Пузырьковая сортировка завершена\n\n");
                memcpy(b, a, sizeof(double) * size);
            }
            else if (sortCheck == 2)
            {
                startTime = clock();
                insertionSort(b, size);
                endTime = clock();
                printf("\nВремя выполнения %lf\n", (endTime - startTime) / 1000);
                printf("Сортировка вставками завершена\n\n");
                memcpy(b, a, sizeof(double) * size);
            }
            else
            {
                startTime = clock();
                quickSort(b, 0, size - 1);
                endTime = clock();
                printf("\nВремя выполнения %lf\n", (endTime - startTime) / 1000);
                printf("Быстрая сортировка завершена\n\n");
                memcpy(b, a, sizeof(double) * size);
            }
        }

        else if (checkbox == 3)
        {
            printf("\n");
        }

        else
        {
            printf("\nВы вышли из программы\n");
            return 0;
        }
    } while (checkbox == 3 || checkbox == 1 || checkbox == 2 || checkbox == 4);
    fclose(file);
    free(a);
    free(b);
}