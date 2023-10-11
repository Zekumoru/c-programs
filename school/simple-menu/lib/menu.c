#include "utils.h"
#include "menu.h"
#include <stdio.h>
#include <ncurses.h>

const int optionsSize = 5;
const char * options[] = {
    "Addizione",
    "Sottraezione",
    "Moltiplicazione",
    "Divisione",
    "Esci"
};
    
int showMenu() {
    int choice;
    
    for (int i = 0; i < optionsSize; i++) {
        println("%d %s", i + 1, options[i]);
    }
    printf("Scelta: ");
    scanf(" %d", &choice);
    
    return choice;
}


int showInteractiveMenu() {
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, true);

    int choice = -1;
    int input;
    int highlight = 0;
    while (choice < 0) {
        clear();

        printwln("Scegli l'operazione:");
        for (int i = 0; i < optionsSize; i++) {
            if (highlight == i) {
                attron(A_REVERSE);
            }

            printwln("%d %s", i + 1, options[i]);
            attroff(A_REVERSE);
        }

        input = getch();

        if (input == KEY_DOWN) {
            highlight++;
            if (highlight > QUIT_OPTION) {
                highlight = 0;
            }
        } else if (input == KEY_UP) {
            highlight--;
            if (highlight < 0) {
                highlight = QUIT_OPTION;
            }
        }

        if (input == KEY_ENTER || input == '\n' || input == '\r') {
            choice = highlight;
        }
    }

    endwin();

    return choice;
}
