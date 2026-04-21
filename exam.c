#include <stdio.h>
#include <locale.h>

int fnum(int start, int end, int res[], int max, int* fcount) {
    int c = 0;

    for (int num = start; num <= end; num++) {      
        int temp = num;
        int dsum = 0;

        while (temp > 0) {
            dsum += temp % 10;  
            temp /= 10;             
        }

        if (dsum * dsum * dsum == num) {
            if (c >= max) {
                *fcount = c;
                return -1; 
            }
            res[c] = num;
            c++;
        }
    }

    *fcount = c;
    return 0; 
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    printf("1. 100-10000\n");
    {
        int res1[10];  
        int c1;
        int s1 = fnum(100, 10000, res1, 10, &c1);

        if (s1 == 0) {
            printf("Найдено чисел: %d\n", c1);
            printf("Числа: ");
            for (int i = 0; i < c1; i++) {
                printf("%d ", res1[i]);
            }
            printf("\n");
        }
        else {
            printf("Ошибка: переполнение массива, найдено не менее %d чисел\n", c1);
            for (int i = 0; i < c1; i++) {
                printf("%d ", res1[i]);
            }
            printf("\n");
        }
    }

    printf("\n2. 100-200\n");
    {
        int res2[5];
        int c2;
        int s2 = fnum(100, 200, res2, 5, &c2);

        if (s2 == 0) {
            printf("Найдено чисел: %d\n", c2);
            if (c2 > 0) {
                printf("Числа: ");
                for (int i = 0; i < c2; i++) {
                    printf("%d ", res2[i]);
                }
                printf("\n");
            }
            else {
                printf("Числа не найдены\n");
            }
        }
    }

    printf("\n3. Проверка переполнения (массив размером 2)\n");
    {
        int res3[2]; 
        int c3;
        int s3 = fnum(100, 10000, res3, 2, &c3);

        if (s3 == 0) {
            printf("Найдено чисел: %d\n", c3);
            printf("Числа: ");
            for (int i = 0; i < c3; i++) {
                printf("%d ", res3[i]);
            }
            printf("\n");
        }
        else {
            printf("Произошло переполнение массива\n");
            printf("Найдено не менее %d чисел\n", c3);
            printf("Первые 2 числа: ");
            for (int i = 0; i < c3; i++) {
                printf("%d ", res3[i]);
            }
            printf("\n");
        }
    }

    printf("\n4. 500-600\n");
    {
        int res4[5];
        int c4;
        int s4 = fnum(500, 600, res4, 5, &c4);

        if (s4 == 0) {
            printf("Найдено чисел: %d\n", c4);
            if (c4 > 0) {
                printf("Числа: ");
                for (int i = 0; i < c4; i++) {
                    printf("%d ", res4[i]);
                }
                printf("\n");
            }
            else {
                printf("Числа не найдены\n");
            }
        }
    }

    return 0;
}
