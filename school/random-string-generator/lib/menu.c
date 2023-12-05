#include "utils.h"
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

MenuItem *createMenuItem(const char *name, MenuItemType type, ...)
{
    MenuItem *item = malloc(sizeof(MenuItem));
    
    va_list params;
    va_start(params, type);
    item->name = v_createFormattedString(name, params);
    va_end(params);

    item->type = type;
    return item;
}

void destroyMenuItem(MenuItem *item) 
{
    free(item->name);
    free(item);
}

int showMenu(Menu *menu)
{
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, true);

    int choice = -1;
    int input;
    int highlight = menu->prevChoice;
    while (choice < 0) {
        clear();

        printwln(menu->title);
        for (int i = 0; i < menu->itemsSize; i++) {
            MenuItem *item = menu->items[i];
            if (highlight == i) {
                attron(A_REVERSE);
            }

            switch (item->type) {
            case BUTTON_MENU_ITEM_TYPE:
                printwln(" %s %s", (highlight == i)? "->" : "  ", item->name);
                break;
            case TOGGLE_MENU_ITEM_TYPE:
                printwln("[%c] %s", (item->toggled)? 'X' : ' ', item->name);
                break;
            default:
                printwln("Error: undefined menu item type");
            }

            attroff(A_REVERSE);
        }

        input = getch();

        if (input == KEY_DOWN || input == 'S' || input == 's') {
            highlight++;
            if (highlight > (menu->itemsSize - 1)) {
                highlight = 0;
            }
        } else if (input == KEY_UP || input == 'W' || input == 'w') {
            highlight--;
            if (highlight < 0) {
                highlight = (menu->itemsSize - 1);
            }
        }

        if (input == KEY_ENTER || input == ' ' || input == '\n' || input == '\r') {
            choice = highlight;
        }
    }

    endwin();
    menu->prevChoice = choice;
    return choice;
}

void destroyMenu(Menu *menu)
{
    free(menu->title);
    for (size_t i = 0; i < menu->itemsSize; i++) {
        destroyMenuItem(menu->items[i]);
    }
    free(menu->items);
    free(menu);
}
