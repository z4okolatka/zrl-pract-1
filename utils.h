#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
int charsToInt(const char *chars, int *err);
bool isValidOperator(const char *ops);
int calculate(int a, const char op, int b);
char *convertToString(int n, int a[n], int k);

#endif