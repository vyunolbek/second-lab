#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const double RAND_MAX_F = RAND_MAX;

int main()
{
    srand(time(NULL));
    FILE* file = fopen("file.txt", "w");
    int size, max, min;

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

    fclose(file);
}
