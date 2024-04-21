/*
Задание. Дан целочисленный массив A[1:n]. Написать программу, включающую две функции с параметрами. 
В первой функции необходимо подсчитать количество повторений каждого элемента массива A. 
Вторая процедура решает следующую задачу:
Сформировать новый массив, содержащий повторяющиеся элементы массива A. 
Элементы в новом массиве не должны повторяться.

Примечание. 
1. Необходима проверка допустимости исходных данных, в том числе недопустим ввод строки вместо числа.
2. При решении задачи необходимо оформить как отдельные функции ввод данных, вывод результатов, обработку массива.
3. Для обращения к элементам массива использовать указатель. Нумерацию элементов массива начать с нуля.
*/

#include <stdio.h>
#define lmax 100

void output(int *k, int B[lmax])
{
    int *i;
    printf("Итоговый массив:\n");
    for (i = B; i < B + *k; i++) {
        printf("%d\n", *i);
    }
}

void input(int A[lmax], int *n)
{
    int x, *i;
    do {
        printf("Введите длину массива\n");
        x = scanf("%d", n);
        while (getchar() != '\n');
    } while (x < 1 || *n < 1 || *n > lmax);
    for (i = A; i < A + *n; i++) {
        do {
            printf("Введите %ld элемент массива\n", i - A + 1);
            x = scanf("%d", i);
            while (getchar() != '\n');
        } while (x < 1);
    }
}

int processing_array(int A[lmax], int B[lmax], int *n, int *k)
{
    int *i, *j, flag;
    for (i = A; i < A + *n - 1; i++) {
        flag = 0;
        for (j = B; j < B + *k && flag == 0; j++) {
            if (*j == *i) {
                flag = 1;
            }
        }
        if (flag == 0) {
            for (j = i + 1; j < A + *n && flag == 0; j++) {
                if (*j == *i) {
                    B[*k] = *i;
                    (*k)++;
                    flag = 1;
                }
            }
        }
    }
}

int main()
{
    int A[lmax], B[lmax], n, k = 0;
    input(A, &n);
    processing_array(A, B, &n, &k);
    output(&k, B);
    return 0;
}
