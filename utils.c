#include "utils.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int charsToInt(const char *str, int *err)
{
    *err = 0;
    int result = 0;
    bool negative = false;
    for (int i = 0; i < strlen(str); i++)
    {
        if (i == 0 && str[i] == '-')
        {
            negative = true;
            continue;
        }
        switch (str[i])
        {
        case '0':
            result = result * 10;
            break;
        case '1':
            result = result * 10 + 1;
            break;
        case '2':
            result = result * 10 + 2;
            break;
        case '3':
            result = result * 10 + 3;
            break;
        case '4':
            result = result * 10 + 4;
            break;
        case '5':
            result = result * 10 + 5;
            break;
        case '6':
            result = result * 10 + 6;
            break;
        case '7':
            result = result * 10 + 7;
            break;
        case '8':
            result = result * 10 + 8;
            break;
        case '9':
            result = result * 10 + 9;
            break;
        default:
            *err = 1;
            return -1;
            break;
        }
    }
    return result * (negative ?: -1);
}

bool isValidOperator(const char *ops)
{
    char op = ops[0];
    return strlen(ops) == 1 && (op == '+' || op == '-' || op == '*' || op == '%');
}

int calculate(int a, const char op, int b)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '%':
        return a % b;
    }
    return -1;
}

char *convertToString(int n, int a[n], int k)
{
    char *res = (char *)malloc(n * sizeof(char));
    for (int i = 0; i < n; i++)
        res[i] = (char)(a[i] - k);
    return res;
}