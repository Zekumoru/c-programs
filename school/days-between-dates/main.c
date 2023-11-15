#include <stdio.h>
#include "lib/date.h"
#include "lib/utils.h"

const int optionsSize = 4;
const char *options[] = {
    "gg/mm/aaaa",
    "mm/gg/aaaa",
    "aaaa/mm/gg",
    "Esci"
};

int main()
{
    // int option = showInteractiveMenu("Scegli il formatto della data:", options, optionsSize);
    println("%s", validateDateFmt("02/29/3332", "mm/dd/yyyy") == 0? "true" : "false");

    return 0;
}
