#include "utils.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#define BACKSPACE_CODE 7

void printwln(const char * fmt, ...) {
    va_list args;
    va_start(args, fmt);

    vw_printw(stdscr, fmt, args);
    printw("\n");

    va_end(args);
}

char * sgetwln(const char * string) {
    int length = (string == NULL) ? 1 : strlen(string) + 1;
    int allocLength = 1;
    while (length >= allocLength && string != NULL) allocLength *= 2;
    char * line = malloc(allocLength);
    if (string == NULL) {
        line[0] = '\0';
    } else {
        memcpy(line, string, length);
    }

    char ch;
    bool backspaceUp = false;
    while ((ch = getch()) != '\n' && ch != EOF) {

        if (ch == BACKSPACE_CODE || ch == KEY_BACKSPACE || ch == '\b') {
            if (length <= 1) {
                move(getcury(stdscr), getcurx(stdscr) + 1);
                continue;
            }

            mvprintw(getcury(stdscr), getcurx(stdscr), " ");
            if (getcurx(stdscr) == 1 && backspaceUp) {
                move(getcury(stdscr) - 1, getmaxx(stdscr) - 1);
                printw(" ");
                move(getcury(stdscr) - 1, getmaxx(stdscr) - 1);
            } else {
                backspaceUp = getcurx(stdscr) == 1;
                move(getcury(stdscr), getcurx(stdscr) - 1);
            }

            line[length - 2] = '\0';
            length--;
            continue;
        }
        
        line[length - 1] = ch;
        length++;
        if (length >= allocLength) {
            allocLength *= 2;
            line = realloc(line, allocLength);
        }
    }
    line[length - 1] = '\0';

    char * temp = line;
    line = malloc(length);
    memcpy(line, temp, length);
    free(temp);

    return line;
}
