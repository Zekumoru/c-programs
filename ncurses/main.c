#include <ncurses.h>

int main() {
    initscr();
    printw("Hello world! Press any key to exit...");
    refresh();
    getch();
    endwin();
    return 0;
}
