#include "lib/utils.h"
#include <ncurses.h>
#include <stdlib.h>

int main() {
    initscr();
    keypad(stdscr, true);

    char * input = malloc(1);
    input[0] = '\0';

    while (true) {
        clear();

        printw("Input: %s", input);
        input = sgetwln(input);
    }

    endwin();
    return 0;
}
