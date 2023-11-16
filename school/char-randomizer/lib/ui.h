#ifndef UI_H
#define UI_H

#include <ncurses.h>
#include <stdbool.h>

void wprintwln(WINDOW *window, const char *fmt, ...);
bool isEnterKey(int key);

void destroyWindow(WINDOW *window);

int showMenuWindow(const char *title, const char *options[], int optionsSize);
int *showGenerateWindow(int *num);
void showLookupWindow(int* countTable, int generatedN);

#endif // UI_H
