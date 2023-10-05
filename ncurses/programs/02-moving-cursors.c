#include "02-moving-cursors.h"
#include <ncurses.h>

int program02() {
    initscr();

    int x = 10;
    int y = 10;

    // Moves cursor to the specified location
    move(y, x);

    // Prints 'Hello world!' to the specified location
    printw("Hello world!");

    // Moves cursor to new line by 3 and first column
    move(y + 3, 0);

    printw("Press any key to continue...");
    getch();

    endwin();
}
