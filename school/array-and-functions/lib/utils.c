#include "utils.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <math.h>
#include <ctype.h>

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

int showInteractiveMenu(const char *title, const char *options[], int optionsSize, int previousChoice)
{
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, true);

    int choice = -1;
    int input;
    int highlight = previousChoice;
    while (choice < 0) {
        clear();

        printwln(title);
        for (int i = 0; i < optionsSize; i++) {
            if (highlight == i) {
                attron(A_REVERSE);
            }

            printwln("%d %s", i + 1, options[i]);
            attroff(A_REVERSE);
        }

        input = getch();

        if (input == KEY_DOWN || input == 'S' || input == 's') {
            highlight++;
            if (highlight > (optionsSize - 1)) {
                highlight = 0;
            }
        } else if (input == KEY_UP || input == 'W' || input == 'w') {
            highlight--;
            if (highlight < 0) {
                highlight = (optionsSize - 1);
            }
        }

        if (input == KEY_ENTER || input == '\n' || input == '\r') {
            choice = highlight;
        }
    }

    endwin();

    return choice;
}
