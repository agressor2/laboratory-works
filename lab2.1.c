/* 
Задание 1. Даны целочисленная матрица A[1:n, 1:m] и целочисленный массив B[1:k].
Упорядочить по убыванию те столбцы матрицы A, все элементы которых присутствуют в массиве B.

Примечания 
1. Необходима проверка допустимости исходных данных. 

2. Необходимо использование алгоритмов с досрочным выходом из цикла. 
При этом используются либо цикл с предусловием, либо цикл с постусловием. 
*/

#include <stdio.h>
#include <math.h>
#define lmax  20

int main()
{
    int n, m, k, A[lmax][lmax], B[lmax], l, i, j, flag, f, v, u, x;
    do { 
        puts("Введите длину и ширину матрицы и длину массива");
        x = scanf("%d %d %d", &n, &m, &k);
        while (getchar() != '\n');
    } while (x < 2 || n < 1 || m < 1 || k < 1 || n > lmax || m > lmax || k > lmax);
    printf("Введите матрицу\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Введите массив\n");
    for (i = 0; i < k; i++) {
        scanf("%d", &B[i]);
    }
    printf("\n");
    for (j = 0; j < m; j++) {
        u = 0;
        flag = 0;
        for (i = 0; i < n; i++) {
            l = 0;
            v = 0;
            do {
                if (A[i][j] == B[l]) {
                    u = u + 1;
                    v = 1;
                }
                else {
                    l += 1;
                }
            }
            while (v == 0 && l < k);
        }
        if (u == n) {
            for (i = 0; i < n; i++) {
                for (l = i; l < n; l++) {
                    if (A[i][j] < A[l][j]) {
                        u = A[i][j];
                        A[i][j] = A[l][j];
                        A[l][j] = u;
                    }
                }
            }
        }
    }
    printf("Матрица\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}
