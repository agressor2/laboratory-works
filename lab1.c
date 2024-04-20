#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define lmax 200

int main() {
    int n, c, b, n1, np, i, k;
    float x, h, a, sr, r[lmax];
    //Задание 1
    printf("Лабораторная работа №1\n");
    printf("Задание №1\n");
    do {
        printf("Введите длину массива R от 1 до %d:", lmax);
        scanf("%d", &n);
    }
    while (n <= 0 || n > lmax);
    printf("Введите x, h, a:");
    scanf("%f", &x);
    scanf("%f", &h);
    scanf("%f", &a);
    for (i = 1; i <= n; i++)
        r[i] = 0.3 * cos(2 * a * x - h * i * i);
    printf("Массив R из %d элементов:\n", n);
    for (i = 1; i <= n; i++)
        printf("%.3f ", r[i]);
    printf("\n");

    //Задание 2
    k = n;  
    printf("Задание №2\n");
    for (n1 = 1, np = 0, i = 1; i <= n; i++) {
    if (r[i] > 0)
        np = i;
    if (fabs(r[i]) > fabs(r[n1]))
        n1 = i;
    }
    if (np == 0)
        printf("Нет положительного элемента\n");
    if (abs(np - n1) < 2)
        printf("Первый максимальный по модулю и последний положительный расположены рядом или совпадают\n");
    else {
        if (n1 < np) {
        c = n1;
        b = np;
        }
        else {
            c = np;
            b = n1;
    }
    k = c;
    for (i = b; i <= n; i++) {
        k = k + 1;
        r[k] = r[i];
    }
    printf("Массив R из %d элементов:\n", k);
    for(i = 1; i <= k; i++)
        printf("%.3f ",r[i]);
    printf("\n");
    }
    //Задание 3 
    printf("Задание №3\n");
    for (n1 = 0, i = k; i >= 1; i--) {
        if (fabs(r[i]) <= fabs(r[n1]))
            n1 = i;  
        if (n1 - 1 <= 0) 
            printf("Нет среднего значения");
        else {
            sr = 0;
            for(i = 1; i <= n1 - 1; i++)
                sr = sr + r[i];
            sr = sr / (n1 - 1);
            printf("sr=%8.3f\n", sr);
        }
    }
return 0;
}
