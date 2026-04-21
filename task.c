#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

char *cutMaxRepeat(char s[])
{
    int len = strlen(s);
    if (len == 0)
    {
        char *result = (char *)malloc(1);
        if (result != NULL)
            result[0] = '\0';
        return result;
    }

    // находим самую длинную подпоследовательность
    int mx = 1, left = 0, i = 0;
    while (i < len)
    {
        int start = i;
        char cur = s[i];
        while (i < len && s[i] == cur)
            i++;
        int cur_len = i - start;
        if (cur_len > mx)
        {
            mx = cur_len;
            left = start;
        }
    }

    if (mx != 1) len -= mx;
    char *result = (char *)malloc(len + 1);
    if (result == NULL)
        return NULL;

    int j = 0;
    // копируем символы до максимально повторяющихся
    for (i = 0; i < left; i++, j++)
        result[j] = s[i];
    i = (mx > 1 ? left + mx : left);
    // коприуем символы после максимально повторяющихся
    while (s[i] != '\0')
    {
        result[j] = s[i];
        j++;
        i++;
    }
    result[j] = '\0';
    return result;
}

int main()
{
    printf("тест 1\n");
    char *result1 = cutMaxRepeat("abcxxxxxacbyyyyyyyyyyyyyyyz");
    printf("input: abcxxxxxacbyyyyyyyyyyyyyyyz\n");
    printf("output: %s\n\n", result1);
    free(result1);

    printf("тест 2\n");
    char *result2 = cutMaxRepeat("abcdef");
    printf("input: abcdef\n");
    printf("output: %s\n\n", result2);
    free(result2);

    printf("тест 3\n");
    char *result3 = cutMaxRepeat("aaaaaaa");
    printf("input: aaaaaaa\n");
    printf("output: %s", result3);
    free(result3);

    return 0;
}