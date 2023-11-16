#include "ui.h"
#include <ncurses.h>
#include <stdarg.h>

void wprintwln(WINDOW *window, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    
    vw_printw(window, fmt, args);
    wprintw(window, "\n");
    
    va_end(args);
}

int showMenuWindow(const char *title, const char *options[], int optionsSize)
{
    noecho();
    curs_set(0);
    keypad(stdscr, true);

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

        if (input == KEY_ENTER || input == '\n' || input == '\r') {
            choice = highlight;
        }
    }

    wclear(menu);
    wrefresh(menu);
    delwin(menu);

    return choice;
}
