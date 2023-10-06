#include "07-user-input.h"
#include <ncurses.h>

WINDOW * createDialog();

int program07() {
    initscr();
    noecho();

    WINDOW * dialog = createDialog();

    // enable the usage of the keypad such as arrow keys
    keypad(dialog, true);

    mvwprintw(dialog, 1, 1, "Press any arrow keys.");
    wrefresh(dialog);

    int ch = wgetch(dialog);
    switch (ch) {
        case KEY_UP:
            mvwprintw(dialog, 2, 1, "You pressed up!");
            break;
        case KEY_RIGHT:
            mvwprintw(dialog, 2, 1, "You pressed right!");
            break;
        case KEY_DOWN:
            mvwprintw(dialog, 2, 1, "You pressed down!");
            break;
        case KEY_LEFT:
            mvwprintw(dialog, 2, 1, "You pressed left!");
            break;
        default:
            mvwprintw(dialog, 2, 1, "You didn't press any arrow keys!");
            break;
    }

    mvwprintw(dialog, 4, 1, "Press any key to exit...");
    wrefresh(dialog);

    getch();
    endwin();

    return 0;
}

WINDOW * createDialog() {
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    int xPad = 2;
    int yPad = 2;
    int dialogWidth = xMax - (xPad * 2);
    int dialogHeight = 6;
    WINDOW * dialog = newwin(dialogHeight, dialogWidth, yMax - dialogHeight - yPad, xPad);
    box(dialog, 0, 0);
    refresh();
    wrefresh(dialog);

    return dialog;
}
