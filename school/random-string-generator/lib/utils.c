#include "utils.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <math.h>
#include <ctype.h>
#include <stdarg.h>

void println(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    
    vprintf(fmt, args);
    printf("\n");
    
    va_end(args);
}

void printwln(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    
    vw_printw(stdscr, fmt, args);
    printw("\n");
    
    va_end(args);
}

char *getln()
{
    int size = 1;
    int allocSize = 1;
    char *line = malloc(allocSize);
    line[0] = '\0';

    char ch;
    while ((ch = getchar()) != '\n' && ch != '\r' && ch != EOF) {
        line[size - 1] = ch;

        size++;
        if (size >= allocSize) {
            allocSize *= 2;
            line = (char*) realloc(line, allocSize);
        }
    }
    
    char *string = malloc(size);
    memcpy(string, line, size);
    string[size - 1] = '\0';
    free(line);

    return string;
}

double toDouble(const char * string, ...) {
    double num = 0.0;
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
            double dec = digit / pow(10, decPlace);
            decPlace++;
            num += dec;
        }
    }

    if (isNeg) num *= -1;

    return num;
}

double getDouble() {
    char * input = getln();
    double num = toDouble(input);
    free(input);
    return num;
}

double getDoubleComma() {
    char * input = getln();
    double num = toDouble(input, true);
    free(input);
    return num;
}

char *createString(const char *_string)
{
    size_t length = strlen(_string);
    char *string = malloc(length + 1);
    strcpy(string, _string);
    string[length] = '\0';
    return string;
}

char *v_createFormattedString(const char *fmt, va_list params)
{
    va_list paramsCopy;
    va_copy(paramsCopy, params);
    
    int length = vsnprintf(NULL, 0, fmt, params) + 1;
    va_end(params);

    char *string = malloc(length);
    vsnprintf(string, length, fmt, paramsCopy);
    va_end(paramsCopy);

    return string;
}

char *createFormattedString(const char *fmt, ...)
{
    va_list params;
    va_start(params, fmt);

    return v_createFormattedString(fmt, params);
}
