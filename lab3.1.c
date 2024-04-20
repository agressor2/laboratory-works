/*
Задание. Оформить в виде функции общую часть в предложенной формуле
Вычислить площадь треугольника с вершинами в точках
P(x1,y1), P(x2,y2),P(x3,y3) по формуле:
S = 0.5 * |(x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3)|

Примечание
1. При решении задачи должна получиться одна функция, вызываемая несколько раз.
*/

#include <stdio.h>
#include <math.h>

float f(float x1, float y1, float x2, float y2) 
{
    return (x1 - x2) * (y1 - y2);
}

int main() 
{
    float x1, x2, x3, y1, y2, y3;
    int x;
    do {
        printf("Введите координаты точки P1\n");
        x = scanf("%f %f", &x1, &y1);
        while (getchar() != '\n');
    } while (x < 2);
    do {
        printf("Введите координаты точки P2\n");
        x = scanf("%f %f", &x2, &y2);
        while (getchar() != '\n');
    } while (x < 2);
    do {
        printf("Введите координаты точки P3\n");
        x = scanf("%f %f", &x3, &y3);
        while (getchar() != '\n');
    } while (x < 2);
    printf("Площадь треугольника равна %.3f", fabs(f(x1, y2, x3, y3) - f(x2, y1, x3, y3)) / 2);
    return 0;
}
