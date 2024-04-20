/*
Задание. 
Найти минимальный элемент среди максимальных элементов каждой строки матрицы C[1:n][1:n]

Примечание. 
При решении задачи использовать две функции – для ввода матрицы и вычисления значения по формуле. 
Для обращения к элементам матрицы использовать указатель.

*/

#include <stdio.h>
#define lmax 100

void input(int n, int C[lmax][lmax]) 
{
    int l, i, *j, x;
    printf("Введите матрицу n * n\n");
    for (i = 0; i < n; i++) {
        l = 0;
        for (j = C[i]; j < C[i] + n; j++) {
            do {
                printf("Введите %d элемент матрицы\n", i * n + l + 1);
                x = scanf("%d", j);
                while (getchar() != '\n');
            } while (x < 1);
            l++;
        }
    }
}

int main() 
{
    int n, i, *j, l, max_element, min_element, C[lmax][lmax], x;
    do {
        printf("Введите n\n");
        x = scanf("%d", &n);
        while (getchar() != '\n');
    } while (x < 1 || n > lmax || n < 1);
    
    input(n, C);
    
    max_element = 0;
    for (l = 0; l < n; l++) {
        min_element = *C[l]; 
        for (i = 0; i < n; i++) {
            if (C[i][l] < min_element) {
                min_element = *(*(C + i) + l);
            }
        }
        if (min_element > max_element) {
            max_element = min_element;
        }
    }
    printf("%d", max_element);
    return 0;
}
