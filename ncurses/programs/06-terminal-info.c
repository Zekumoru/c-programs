#include "06-terminal-info.h"
#include <ncurses.h>
#include <stdarg.h>
#include <string.h>

void centerPrint(int yOff, int xOff, const char * fmt, ...);

int program06() {
    initscr();

    int y, x;
    int yBeg, xBeg;
    int yMax, xMax;
    const char title[] = "Terminal Infos";

    centerPrint(-2, 0, title);

    getyx(stdscr, y, x);
    centerPrint(-1, 0, "Cursor Y: %d | X: %d", y, x);
    
    getbegyx(stdscr, yBeg, xBeg);
    centerPrint(0, 0, "Beginning Y: %d | X: %d", yBeg, xBeg);
    
    getmaxyx(stdscr, yMax, xMax);
    centerPrint(1, 0, "Max Y: %d | X: %d", yMax, xMax);
    
    centerPrint(2, 0, "Press any key to exit...");
    getch();

    endwin();

    return 0;
}

void centerPrint(int yOff, int xOff, const char * fmt, ...) {
    va_list args;
    va_start(args, fmt);

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    int yOffset = yMax / 2 + yOff;
    int xOffset = (xMax - strlen(fmt)) / 2 + xOff;

    move(yOffset, xOffset);
    vw_printw(stdscr, fmt, args);

    va_end(args);
}
