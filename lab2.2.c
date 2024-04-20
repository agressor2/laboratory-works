/*
Дан массив целых положительных чисел. 

Для каждого элемента массива произвести циклическую перестановку цифр на одну цифру вправо. Например, 1623-> 3162. 

Примечание
1. Необходима проверка допустимости исходных данных, в том числе недопустим ввод строки вместо числа.

2. При вычислении результата необходимо использовать целый тип. Использование строк при решении данной задачи недопустимо.
*/

#include <stdio.h>
#include <math.h>
#define lmax 20

int main()
{
    int n, m, k, b[lmax], f, u, x;
    do {
        puts("Введите длину массива");
        x = scanf("%d", &k);
        while (getchar() != '\n');
    } while (x < 1 || k > lmax || k <= 0);
    for (int i = 0; i < k; i++){
        do {
            printf("Введите %d элемент массива\n", i + 1);
            x = scanf("%d", &u);
            while (getchar() != '\n');
        } while (x < 1 || u < 1);
        b[i] = u;
    }
    printf("Массив\n");
    for (int l = 0; l < k; l++){
        n = b[l];
        m = -1;
        while (n > 0){
            m += 1;
            n = n / 10;
        }
        u = b[l] % 10;
        u = u * pow(10, m);
        f = b[l] / 10 ;
        printf("%d ", f + u);
    }
    return 0;
}
