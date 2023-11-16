#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include "lib/randomizer.h"
#include "lib/ui.h"

const int optionsSize = 4;
const char *options[] = {
    "Generate",
    "Lookup",
    "List Counts",
    "Exit"
};
enum Options {
    GENERATE_OPTION,
    LOOKUP_OPTION,
    LIST_COUNTS_OPTION,
    EXIT_OPTION
};

int main()
{
    srand(time(NULL));
    initscr();

    int *countTable = NULL;
    int generatedN = 0;

    int option;
    while ((option = showMenuWindow("Character Generator", options, optionsSize)) != EXIT_OPTION) {
        switch (option) {
        case GENERATE_OPTION:
            countTable = showGenerateWindow(&generatedN);
            break;
        case LOOKUP_OPTION:
            showLookupWindow(countTable, generatedN);
            break;
        case LIST_COUNTS_OPTION:
            showListCounts(countTable, generatedN);
            break;
        }
    }

    endwin();
    free(countTable);

    return 0;
}
