#ifndef UI_H
#define UI_H

#include <ncurses.h>

void wprintwln(WINDOW *window, const char *fmt, ...);

int showMenuWindow(const char *title, const char *options[], int optionsSize);

#endif // UI_H
