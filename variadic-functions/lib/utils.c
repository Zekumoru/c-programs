#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void println(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    
    vprintf(fmt, args);
    printf("\n");

    va_end(args);
}

char* getln() {
    int size = 1;
    int allocSize = 1;
    char * line = malloc(allocSize);
    line[0] = '\0';

    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        line[size - 1] = ch;

        size++;
        if (size >= allocSize) {
            allocSize *= 2;
            line = (char*) realloc(line, allocSize);
        }
    }
    
    char * string = malloc(size);
    memcpy(string, line, size);
    string[size - 1] = '\0';
    free(line);

    return string;
}

int toInt(const char* string) {
    int num = 0;
    int pos = 0;
    bool isNeg = false;

    for (int i = 0; isspace(string[i]); i++, pos++);
    
    isNeg = string[pos] == '-';
    if (isNeg) pos++;

    for (; isdigit(string[pos]); pos++) {
        num *= 10;
        num += string[pos] - '0';
    }

    if (isNeg) num *= -1;

    return num;
}

int getInt() {
    char * input = getln();
    int num = toInt(input);
    free(input);
    return num;
}
