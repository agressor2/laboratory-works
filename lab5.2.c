/*
Задание. Создать текстовый файл средствами редактора (т.е. в «Блокноте»). 
Прочитать этот файл построчно и произвести в каждой строке следующие действия:
переставить все символы в строке в обратной последовательности

Примечание. Записать каждую полученную строку в новый текстовый файл и вывести полученные строки из файла на экран. 
Имена входного и выходного файла задаются пользователем.
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define lmax 200

void fillFile(char *filename, char a[lmax][lmax])
{
    FILE *f;
    f = fopen(filename, "w");
    for (int i = 0; a[i][0]; i++) {
        fputs(a[i], f);
        fputc('\n', f);
    }
    fclose(f);
}

void getArray(char *filename, int *n, char a[lmax][lmax])
{
   FILE *f;
   char c;
   f = fopen(filename, "r");
   *n = 0;
   while(!feof(f))
        if ((fscanf(f, "%s", a[*n])) == 1) {
            (*n)++;
        }
        else {
            while((c = fgetc(f)) != '\n' && c != EOF);
        }  
    fclose(f);
}

int main()
{
    char filename[lmax], a[lmax][lmax];
    int n, positive_numbers = 0;
    do {
        printf("Введите название существующего файла\n");
        scanf("%s", filename);
        while (getchar() != '\n');
    } while (fopen(filename, "r") == 0);
    getArray(filename, &n, a);
    for (int i = 0; i < n; i++) {
        printf("%s\n", a[i]);
    }
    printf("Введите название файла\n");
    scanf("%s", filename);
    int j, p;
    for (int i = 0; i < n; i++) {
        for (j = 0; a[i][j]; j++) {}
        for (int l = 0; l < j / 2; l++) {
            p = a[i][l];
            a[i][l] = a[i][j - l - 1];
            a[i][j - l - 1] = p;
        }
        printf("%s\n", a[i]);
    }
    fillFile(filename, a);
    return 0;
}
