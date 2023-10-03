#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

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

float toFloat(const char* string, ...) {
    float num = 0.0;
    int pos = 0;
    bool isNeg = false;
    bool dotFound = false;
    bool useComma = false;

    va_list args;
    va_start(args, string);
    useComma = va_arg(args, int) == true;
    va_end(args);

    for (int i = 0; isspace(string[i]); i++, pos++);

    isNeg = string[pos] == '-';
    if (isNeg) pos++;

    for (int decPlace = 1; isdigit(string[pos]) || string[pos] == '.' || (useComma && string[pos] == ','); pos++) {
        if (string[pos] == '.' || (useComma && string[pos] == ',')) {
            if (dotFound) break;

            dotFound = true;
            continue;
        }

        int digit = string[pos] - '0';
        if (!dotFound) {
            num *= 10;
            num += digit;
        } else {
            float dec = digit / pow(10, decPlace);
            decPlace++;
            num += dec;
        }
    }

    if (isNeg) num *= -1;

    return num;
}

float getFloat() {
    char * input = getln();
    float num = toFloat(input);
    free(input);
    return num;
}

float getFloatComma() {
    char * input = getln();
    float num = toFloat(input, true);
    free(input);
    return num;
}
