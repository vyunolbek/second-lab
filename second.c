#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <math.h>

const double RAND_MAX_F = RAND_MAX;

int stringCount(FILE* strC) {
    int result = 0;
    while (!ferror(strC) && !feof(strC)) {
        if (fgetc(strC) == '\n')
            result++;
    }
    rewind(strC);
    return result;
}

void clrscr()
{
    system("@cls||clear");
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

int main(int argc, char* argv[])  
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    FILE* file = fopen("../first/file.txt", "r");
    int size, checkbox = 0, sortCheck = 0, norma = 0, geld = 0;
    double startTime, endTime, vichisl = 0;
    printf_s("Чтение из файла...\n");
    size = stringCount(file);
    double* b, * a;

    a = (double*)malloc(size * sizeof(double));
    b = (double*)malloc(size * sizeof(double));

    if (a == 0 || b == 0)
        return 1;

    for (int i = 0; i < size; i++)
        fscanf_s(file, "%lf", &a[i]);

    clrscr();
    memcpy(b, a, sizeof(double) * size);

    if (argc > 1)
    {
        if (strcmp(argv[1], "bubble") == 0)
        {
            startTime = clock();
            bubbleSort(b, size);
            endTime = clock();
            printf_s("Время выполнения %lf\n", (endTime - startTime) / 1000);
            printf_s("Пузырьковая сортировка завершена\n\n");
        }
        else if (strcmp(argv[1], "insertion") == 0)
        {
            startTime = clock();
            insertionSort(b, size);
            endTime = clock();
            printf_s("Время выполнения %lf\n", (endTime - startTime) / 1000);
            printf_s("Сортировка вставками завершена\n\n");
        }
        else if (strcmp(argv[1], "quick") == 0)
        {
            startTime = clock();
            quickSort(b, 0, size - 1);
            endTime = clock();
            printf_s("Время выполнения %lf\n", (endTime - startTime) / 1000);
            printf_s("Быстрая сортировка завершена\n\n");
        }
        return 0;
    }

    do
    {
        printf_s("Выберите нужное действие:\n1. Печать\n2. Сортировка\n3. Сброс\n4. Норма вектора\n5. Выход\nВыбор:");
        do
        {
            scanf_s("%d", &checkbox);
            if (checkbox < 1 || checkbox > 5)
            {
                printf_s("\nВы неверно ввели номер. Введите снова\n\nВыбор:");
            }
        } while (checkbox < 1 || checkbox > 5);
        if (checkbox == 1)
        {
            clrscr();
            for (int i = 0; i < size; i++)
                printf_s("a[%d] = %lf\n", i, b[i]);
            printf_s("\n");
        }
        else if (checkbox == 2)
        {
            clrscr();
            printf_s("Выберите сортировку:\n1. Пузырьком\n2. Вставками\n3. Быстрая\n-----------\n4. Назад в меню\nВыбор:");
            do
            {
                scanf_s("%d", &sortCheck);
                if (sortCheck < 1 || sortCheck > 4)
                    printf_s("\nВы неверно ввели номер. Введите снова\n\nВыбор:");
            } while (sortCheck < 1 || sortCheck > 4);
            switch (sortCheck)
            {
                case 1:
                    clrscr();
                    startTime = clock();
                    bubbleSort(b, size);
                    endTime = clock();
                    printf_s("Время выполнения %lf\n", (endTime - startTime) / 1000);
                    printf_s("Пузырьковая сортировка завершена\n\n");
                    break;
                case 2:
                    clrscr();
                    startTime = clock();
                    insertionSort(b, size);
                    endTime = clock();
                    printf_s("Время выполнения %lf\n", (endTime - startTime) / 1000);
                    printf_s("Сортировка вставками завершена\n\n");
                    break;
                case 3:
                    clrscr();
                    startTime = clock();
                    quickSort(b, 0, size - 1);
                    endTime = clock();
                    printf_s("Время выполнения %lf\n", (endTime - startTime) / 1000);
                    printf_s("Быстрая сортировка завершена\n\n");
                    break;
                default:
                    clrscr();
                    break;
            }
        }
        else if (checkbox == 3)
        {
            clrscr();
            memcpy(b, a, sizeof(double) * size);
            printf_s("Сортировка сброшена\n\n");
        }
        else if (checkbox == 4)
        {
            clrscr();
            printf_s("Введите норму вектора (0 если бесконечная, -1 если нормировка массива, -2 если Гёльдерова):");
            scanf_s("%d", &norma);
            if (norma == 1)
            {
                for (int k = 0; k < size; k++)
                {
                    vichisl += fabs(pow(b[k], 1));
                }
                printf_s("\nНорма вектора = %lf\n\n", pow(vichisl, (1 / 1)));
            }
            else if (norma == 2)
            {
                for (int k = 0; k < size; k++)
                {
                    vichisl += fabs(pow(b[k], 2));
                }
                printf_s("\nНорма вектора = %lf\n\n", pow(vichisl, (1 / 2)));
            }
            else if(norma == 0)
            {
                quickSort(b, 0, size - 1);
                vichisl = fabs(b[size - 1]);
                printf("\nНорма вектора = %lf\n\n", vichisl);
            }
            else if (norma == -1)
            {
                for (int i = 0; i < size; i++)
                {
                    vichisl += fabs(pow(b[i], 2));
                }
                for (int i = 0; i < size; i++)
                {
                    a[i] = a[i] / pow(vichisl, 1 / (double)2);
                    printf("a[%d] = %lf\n", i, a[i]);
                }
            }
            else if (norma == -2)
            {
                printf_s("\nВведите норму:");
                scanf_s("%d", &geld);
                for (int k = 0; k < size; k++)
                {
                    vichisl += fabs(pow(b[k], geld));
                }
                printf_s("\nНорма вектора = %lf\n\n", pow(vichisl, (1 / (double)geld)));
            }
        }
        else
        {
            printf_s("\nВы вышли из программы\n");
            return 0;
        }
    } while (checkbox == 3 || checkbox == 1 || checkbox == 2 || checkbox == 4 || checkbox == 5);
    fclose(file);
    free(a);
    free(b);
}