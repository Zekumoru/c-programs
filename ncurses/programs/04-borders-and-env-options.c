#include "04-borders-and-env-options.h"
#include <ncurses.h>

void createWindow();

int program04() {
    initscr();

    // This is default behaviour. It lets the use of 
    // Ctrl + C to exit out of window.
    cbreak();

    // This is like the opposite of cbreak(). 
    // Ctrl + C will not exit out of the window. Rather,
    // it will take them as two distinct inputs: 'Ctrl' and '+'
    raw();
    cbreak();

    // This prevents inputs from being outputted on the screen.
    noecho();

    // This is default behaviour. It negates noecho().
    echo();

    createWindow();

    endwin();

    return 0;
}

void createWindow() {
    int height = 10;
    int width = 20;
    int startY = 7;
    int startX = 5;

    WINDOW * win = newwin(height, width, startY, startX);
    refresh();

    char leftBorder;
    char rightBorder;
    char topBorder;
    char bottomBorder;
    char topLeftBorder;
    char topRightBorder;
    char bottomLeftBorder;
    char bottomRightBorder;

    leftBorder = rightBorder = '|';
    topBorder = bottomBorder = '-';
    topLeftBorder = topRightBorder = bottomLeftBorder = bottomRightBorder = '+';

    wborder(
        win, 
        leftBorder, 
        rightBorder,
        topBorder,
        bottomBorder,
        topLeftBorder,
        topRightBorder,
        bottomLeftBorder,
        bottomRightBorder 
    );

    mvwprintw(win, 1, 1, "This is a box.");
    wrefresh(win);

    mvprintw(startY + height + 3, 0, "Press any key to exit...");
    getch();
}
