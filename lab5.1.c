#include <stdio.h>
#include <stdlib.h>
#define lmax 200

void getArray(char *filename, int *n, float a[])
{ 
   FILE *f; 
   char c;
   if (!(f = fopen(filename, "r"))) {      
        puts("File not found");
        exit(1);
   }
   *n = 0;
   while(!feof(f))
        if ((fscanf(f, "%f", &a[*n])) == 1) {
            (*n)++;
        }
        else {
            while((c = fgetc(f)) != '\n' && c != EOF);
        }  
    fclose(f);
}

int main()
{
    char filename[lmax];
    float a[lmax];
    int n, positive_numbers = 0;
    do {
        printf("Введите название существующего файла\n");
        scanf("%s", filename);
        while (getchar() != '\n');
    } while (fopen(filename, "r") == 0);
    
    getArray(filename, &n, a);
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            positive_numbers++;
        }
    }
    printf("%d", positive_numbers);
    return 0;
}
