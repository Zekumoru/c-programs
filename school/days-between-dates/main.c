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
    Date *date;
    println("%s", validateDateFmt("02/29/3332", "mm/dd/yyyy", &date) == 0? "true" : "false");

    println("%04d/%02d/%02d", date->year, date->month, date->day);
    
    return 0;
}
