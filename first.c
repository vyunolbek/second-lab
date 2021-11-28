#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>

const double RAND_MAX_F = RAND_MAX;

void clrscr()
{
    system("@cls||clear");
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    FILE* file = fopen("file.txt", "w");
    FILE* file2 = fopen("file2.txt", "r");
    int size, max, min, checkbox = 0;
    char stop[5];
    do
    {
        printf_s("Выберите способ задания\n1. Рандомно\n2. Вручную\n3. Из другого файла\nВвод:");
        scanf_s("%d", &checkbox);
        printf_s("\n");
        if (checkbox == 1) 
        {
            clrscr();
            printf("Введите кол-во элементов в массиве: ");
            scanf_s("%d", &size);
            printf("Введите минимальный элемент: ");
            scanf_s("%d", &min);
            printf("Введите максимальный элемент: ");
            scanf_s("%d", &max);
            for (int i = 0; i < size; i++)
            {
                fprintf(file, "%lf\n", (rand() / RAND_MAX_F) * ((double)max - (double)min) + min);
            }
            return 0;
        }
        else if (checkbox == 2)
        {
            double num;
            clrscr();
            do
            {
                printf("Введите кол-во чисел:");
                scanf_s("%d", &size);
                for (int i = 0; i < size; i++)
                {
                    scanf_s("%lf", &num);
                    fprintf_s(file, "%lf\n", num);
                }
                if (size <= 0)
                {
                    printf("\nВы неверно ввели данные, введите снова\n\n");
                }
            } while (size <= 0);
            return 0;
        }
        else
        {
            fscanf_s(file2, "%d\n", &size);
            double* array;
            array = (double*)malloc(size * sizeof(double));
            for (int i = 0; i < size; i++)
                fscanf_s(file2, "%lf\n", &array[i]);
            for (int i = 0; i < size; i++)
                fprintf_s(file, "%lf\n", array[i]);
            printf_s("Массив задан");
            return 0;
        }
        if (size <= 0 || min > max || 1 <= checkbox <= 3)
        {
            clrscr();
            printf_s("Вы неверно ввели данные. Введите снова\n\n");
        }
    } while (size <= 0 || min > max || 1 <= checkbox <= 3);

    

    fclose(file);
}