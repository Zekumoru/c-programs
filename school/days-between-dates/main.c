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

int main()
{
    Date *d1 = NULL;
    Date *d2 = NULL;

    int option = showInteractiveMenu("Scegli il formatto della data:", options, optionsSize);
    if (option == optionsSize - 1) return 0;

    d1 = getDateInput("Inserisci la prima data", option);
    d2 = getDateInput("Inserisci la seconda data", option);

    println("I numeri di giorni tra quelle date sono: %d giorni", countDays(d1, d2));
    
    free(d1);
    free(d2);

    return 0;
}
