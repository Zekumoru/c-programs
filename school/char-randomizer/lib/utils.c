#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

void println(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    
    vprintf(fmt, args);
    printf("\n");
    
    va_end(args);
}

char *getln()
{
    int size = 1;
    int allocSize = 1;
    char *line = malloc(allocSize);
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
    
    char *string = malloc(size);
    memcpy(string, line, size);
    string[size - 1] = '\0';
    free(line);

    return string;
}