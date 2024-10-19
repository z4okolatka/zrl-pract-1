#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
int charsToInt(const char *, int *);
bool isValidOperator(const char *);
int calculate(int, const char, int);
char *convertToString(int, int[], int);

#endif