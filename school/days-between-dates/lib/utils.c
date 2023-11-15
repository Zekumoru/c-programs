#include "utils.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

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

int showInteractiveMenu(const char *title, const char *options[], int optionsSize)
{
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, true);

    int choice = -1;
    int input;
    int highlight = 0;
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

        if (input == KEY_DOWN) {
            highlight++;
            if (highlight > (optionsSize - 1)) {
                highlight = 0;
            }
        } else if (input == KEY_UP) {
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
