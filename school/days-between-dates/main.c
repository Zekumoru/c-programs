#include "lib/date.h"
#include "lib/utils.h"
#include "lib/date-input.h"
#include <stdlib.h>
#include <math.h>

const int optionsSize = 4;
const char *options[] = {
    "gg/mm/aaaa",
    "mm/gg/aaaa",
    "aaaa/mm/gg",
    "Esci"
};
enum MenuOptions {
    IT_FORMAT_OPTION,
    US_FORMAT_OPTION,
    DEV_FORMAT_OPTION,
    EXIT_OPTION
};

int main()
{
    Date *d1 = NULL;
    Date *d2 = NULL;

    int option;
    while ((option = showInteractiveMenu("Scegli il formatto della data:", options, optionsSize)) != EXIT_OPTION) {
        if (option == optionsSize - 1) return 0;

        d1 = getDateInput("Inserisci la prima data", option);
        d2 = getDateInput("Inserisci la seconda data", option);

        println("I numeri di giorni tra quelle date sono: %d giorni", countDays(d1, d2));
        println("Premere 'Invio' per tornare al menu...");
        getln();

        free(d1);
        free(d2);
    }

    return 0;
}
