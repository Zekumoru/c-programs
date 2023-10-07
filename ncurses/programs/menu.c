#include "menu.h"
#include <ncurses.h>
#include "utils.h"
#include "01-hello-world.h"
#include "02-moving-cursors.h"
#include "03-windows-basics.h"
#include "04-borders-and-env-options.h"
#include "05-attr-and-colors.h"
#include "06-terminal-info.h"
#include "07-user-input.h"

void init();
int processSelection(int choice);

int showMenu() {
    init();

    int key;
    int choice = -1;
    int highlight = 0;
    while (choice != QUIT_OPTION) {
        clear();

        printwln("Select program:");
        printwln("");
        for (int i = 0; i < OPTIONS_SIZE; i++) {
            if (i == highlight) attron(A_REVERSE);
            printwln("%s", OPTIONS[i]);
            attroff(A_REVERSE);
        }
        printwln("");
        printwln("Press ^ and v to move between options. Press space to select.");
        
        key = getch();
        if (key == KEY_UP) {
            highlight--;
            if (highlight < 0) highlight = OPTIONS_SIZE - 1;
        } else if (key == KEY_DOWN) {
            highlight++;
            if (highlight >= OPTIONS_SIZE) highlight = 0;
        } else if (key == ' ') {
            choice = highlight;
            if (choice == QUIT_OPTION) break;
            processSelection(choice);
            choice = -1;
        }

    }

    endwin();

    return 0;
}

void init() {
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, true);
}

int processSelection(int choice) {
    clear();
    endwin();

    int exitCode = 0;
    switch (choice) {
        case HELLO_WORLD_OPTION:
            exitCode = program01();
            break;
        case MOVING_CURSORS_OPTION:
            exitCode = program02();
            break;
        case WINDOWS_BASICS_OPTION:
            exitCode = program03();
            break;
        case BORDERS_AND_ENV_OPTIONS_OPTION:
            exitCode = program04();
            break;
        case ATTR_AND_COLORS_OPTION:
            exitCode = program05();
            break;
        case TERMINAL_INFO_OPTION:
            exitCode = program06();
            break;
        case USER_INPUT_OPTION:
            exitCode = program07();
            break;
    }
    init();

    return exitCode;
}
