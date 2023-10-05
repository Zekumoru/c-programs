#include "01-hello-world.h"
#include <ncurses.h>

int program01() {
    // Initialize ncurses window in memory
    initscr(); 
    
    // Print to main window, also called stdscr
    printw("Hello world!\n");
    
    // Prevent window from exiting until user presses a key
    printw("Press any key to exit...");
    getch();

    // Free ncurses from memory
    endwin();

    return 0;
}
