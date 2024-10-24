#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

int main(int argc, char *argv[argc])
{
    if (argc < 6) {
        printf("error: not enough arguments\n");
        return -1;
    }
    if (argc % 3 != 0)
    {
        printf("error: wrong number of arguments\n");
        return -1;
    }
    int resultsCount = argc / 3 - 1;
    int *results = (int *)malloc(sizeof(int) * resultsCount);
    int err = 0;
    for (int i = 1; i < argc - 2; i += 3)
    {
        int a = charsToInt(argv[i], &err);
        if (err == 1)
        {
            printf("error: argument `%s` at position %d is not an integer\n", argv[i], i);
            free(results);
            return -1;
        }
        if (!isValidOperator(argv[i + 1]))
        {
            printf("error: argument `%s` at position %d is not a valid operator (%%, *, -, +)\n", argv[i + 1], i + 1);
            free(results);
            return -1;
        }
        char op = argv[i + 1][0];
        int b = charsToInt(argv[i + 2], &err);
        if (err == 1)
        {
            printf("error: argument `%s` at position %d is not an integer\n", argv[i + 2], i + 2);
            free(results);
            return -1;
        }
        results[i / 3] = calculate(a, op, b);
        printf("Ответ %d. %d\n", i / 3 + 1, results[i / 3]);
    }
    if (strcmp(argv[argc - 2], "-k") != 0)
    {
        printf("wrong flag `%s` at position %d. must be -k", argv[argc - 2], argc - 2);
        free(results);
        return -1;
    }
    int k = charsToInt(argv[argc - 1], &err);
    if (err == 1)
    {
        printf("error: argument `%s` after `-k` is not an integer\n", argv[argc - 1]);
        free(results);
        return -1;
    }
    printf("Результирующая строка: %s\n", convertToString(resultsCount, results, k));
    return 0;
}