/*Сформировать массив простых чисел в диапазоне от 2 до заданного. Очередное простое число определяется попыткой деления нацело числа на все уже накопленные простые числа. Проверить свойство найденных чисел: сумма цифр простого числа в системе счисления по основания 7 также является простым числом. Заполнить в выходном массиве все исключения (пары: число и сумма цифр)*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Простое ли число
static int prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

// Сумма цифр в 7-ричной
static int sum7(int n) {
    int s = 0;
    while (n) {
        s += n % 7;
        n /= 7;
    }
    return s;
}

/*
 * Находит исключения
 * exc - массив чисел
 * s - массив сумм
 * cnt - количество
 */
int get_exceptions(int max, int** exc, int** s, int* cnt) {
    *exc = *s = NULL;
    *cnt = 0;

    if (max < 2) return 0;

    // Простые числа
    int* p = (int*)malloc((max + 1) * sizeof(int));
    int pc = 0;

    for (int n = 2; n <= max; n++) {
        int pr = 1;
        for (int i = 0; i < pc; i++) {
            if (n % p[i] == 0) {
                pr = 0;
                break;
            }
        }
        if (pr) p[pc++] = n;
    }

    // Ищем исключения
    int e = 0;
    for (int i = 0; i < pc; i++) {
        if (!prime(sum7(p[i]))) e++;
    }

    if (e) {
        *exc = (int*)malloc(e * sizeof(int));
        *s = (int*)malloc(e * sizeof(int));

        int idx = 0;
        for (int i = 0; i < pc; i++) {
            int sm = sum7(p[i]);
            if (!prime(sm)) {
                (*exc)[idx] = p[i];
                (*s)[idx] = sm;
                idx++;
            }
        }
        *cnt = e;
    }

    free(p);
    return 0;
}

int main() {
    int N;
    scanf("%d", &N);
    printf("N = ");
    printf("%d", N);
    // Результат
    int* exc = NULL;
    int* sum = NULL;
    int cnt = 0;

    // Вызов
    get_exceptions(N, &exc, &sum, &cnt);

    // Вывод в формате: число - сумма
    printf("\n Исключения: \n");
    for (int i = 0; i < cnt; i++) {
        printf("%d - %d\n", exc[i], sum[i]);
    }

    // Очистка
    if (exc) free(exc);
    if (sum) free(sum);

    return 0;
}
