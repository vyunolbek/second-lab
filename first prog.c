#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const double RAND_MAX_F = RAND_MAX;

void clrscr()
{
    system("@cls||clear");
}

int main()
{
    srand(time(NULL));
    FILE* file = fopen("file.txt", "w");
    int size, max, min;

    do
    {
        printf("Введите кол-во элементов в массиве: ");
        scanf_s("%d", &size);
        printf("Введите минимальный элемент: ");
        scanf_s("%d", &min);
        printf("Введите максимальный элемент: ");
        scanf_s("%d", &max);
        if (size <= 0 || min > max)
        {
            clrscr();
            printf_s("Вы неверно ввели данные. Введите снова\n\n");
        }
    } while (size <= 0 || min > max);

    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%lf\n", (rand() / RAND_MAX_F) * ((double)max - (double)min) + min);
    }

    fclose(file);
}