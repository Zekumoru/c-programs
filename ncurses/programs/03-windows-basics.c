#include "03-windows-basics.h"
#include <ncurses.h>

int program03() {
    initscr();

    int height, width, startY, startX;
    height = 10;
    width = 20;
    startY = 5;
    startX = 7;

    // create a new window for ncurses
    WINDOW* win = newwin(height, width, startY, startX);
    // refresh main window to draw window
    // (though it'll be invisible at this point)
    refresh();

    // draw borders around the window
    box(win, 0, 0);

    // prints the string below in the window
    mvwprintw(win, 1, 1, "This is my box.");

    // Updates the screen to show win
    wrefresh(win);

    // prints the string below in the main window
    mvprintw(height + startY + 3, 0, "Press any key to exit...");
    getch();

    endwin();

    return 0;
}