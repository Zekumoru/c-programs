#include "03-windows-basics.h"
#include <ncurses.h>

int program03() {
    initscr();

    int height, width, startY, startX;
    height = 10;
    width = 20;
    startY = 5;
    startX = 7;

    WINDOW* win = newwin(height, width, startY, startX);
    refresh();

    box(win, 0, 0);

    mvwprintw(win, 1, 1, "This is my box.");
    wrefresh(win);

    mvprintw(height + startY + 3, 0, "Press any key to exit...");
    getch();

    endwin();

    return 0;
}