#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include "lib/randomizer.h"
#include "lib/ui.h"

const int optionsSize = 3;
const char *options[] = {
    "Generate",
    "Lookup",
    "Exit"
};
enum Options {
    GENERATE_OPTION,
    LOOKUP_OPTION,
    EXIT_OPTION
};

int main()
{
    initscr();

    int option;
    while ((option = showMenuWindow("Character Generator", options, optionsSize)) != EXIT_OPTION) {
        
    }

    endwin();

    return 0;
}
