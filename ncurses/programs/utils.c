#include "utils.h"
#include <ncurses.h>
#include <stdarg.h>

void printwln(const char * fmt, ...) {
    va_list args;
    va_start(args, fmt);

    vw_printw(stdscr, fmt, args);
    printw("\n");

    va_end(args);
}
