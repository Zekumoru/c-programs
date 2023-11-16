#include "ui.h"
#include <ncurses.h>
#include <stdarg.h>
#include <stdbool.h>
#include "randomizer.h"

void wprintwln(WINDOW *window, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    
    vw_printw(window, fmt, args);
    wprintw(window, "\n");
    
    va_end(args);
}

bool isEnterKey(int key) 
{
    return key == KEY_ENTER || key == '\n' || key == '\r';
}

void destroyWindow(WINDOW *window)
{
    wclear(window);
    wrefresh(window);
    delwin(window);
}

int showMenuWindow(const char *title, const char *options[], int optionsSize)
{
    noecho(); // turn off pressed keys printing out
    curs_set(0); // hide cursor
    keypad(stdscr, true); // allow arrow keys press

    WINDOW *menu = newwin(LINES, COLS, 0, 0);
    refresh();

    int choice = -1;
    int input;
    int highlight = 0;
    while (choice < 0) {
        wclear(menu);

        wprintwln(menu, title);
        for (int i = 0; i < optionsSize; i++) {
            wprintw(menu, (highlight == i)? "-> " : "   ");
            wprintwln(menu, "%s", options[i]);
        }

        wrefresh(menu);
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

        if (isEnterKey(input)) {
            choice = highlight;
        }
    }

    destroyWindow(menu);

    return choice;
}

int *showGenerateWindow()
{
    noecho(); // turn off pressed keys printing out
    curs_set(0); // hide cursor
    keypad(stdscr, true); // allow arrow keys press

    WINDOW *window = newwin(LINES, COLS, 0, 0);
    refresh();

    int num = 100;
    int input = 0;
    while (!isEnterKey(input)) {
        wclear(window);
        wprintwln(window, "How many characters to generate? (Use arrow keys)");
        wprintwln(window, "             ^^^ (*10)");
        wprintwln(window, "(-10) <-- %d characters --> (+10)", num);
        wprintwln(window, "             vvv (/10)");
        wrefresh(window);
        input = getch();

        switch(input) {
        case KEY_UP:
            if (num < 1000000) num *= 10;
            if (num >= 1000000) num = 9999990;
            break;
        case KEY_DOWN:
            if (num < 100) num = 10;
            if (num > 10) num /= 10;
            break;
        case KEY_RIGHT:
            if (num < 10000000) num += 10;
            break;
        case KEY_LEFT:
            if (num > 10) num -= 10;
            break;
        }
    }

    int *countTable = generateCountTable(num);
    wclear(window);
    wprintwln(window, "Generated %d characters!", num);
    wprintwln(window, "Press any keys to return to menu...");
    wrefresh(window);
    getch();

    destroyWindow(window);

    return countTable;
}
