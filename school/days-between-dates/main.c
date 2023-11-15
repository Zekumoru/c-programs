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
const char *dateFormats[] = {
    "dd/mm/yyyy",
    "mm/dd/yyyy",
    "yyyy/mm/dd"
};

Date *getDateInput(const char *prompt, int fmtOption);

int main()
{
    Date *d1 = NULL;
    Date *d2 = NULL;

    int option = showInteractiveMenu("Scegli il formatto della data:", options, optionsSize);
    if (option == optionsSize - 1) return 0;

    d1 = getDateInput("Inserisci la prima data", option);
    d2 = getDateInput("Inserisci la seconda data", option);

    println("I numeri di giorni tra quelle date sono: %d giorni", countDays(d1, d2));
    
    return 0;
}

Date *getDateInput(const char *prompt, int fmtOption)
{
    Date *date;
    int validationResult;
    
    do {
        printf("%s [%s]: ", prompt, dateFormats[fmtOption]);
        const char *input = getln();
        
        int maxDay = 0;
        validationResult = validateDateFmt(input, dateFormats[fmtOption], &date, &maxDay);
        switch (validationResult) {
            case LENGTH_ERROR:
            case FORMAT_ERROR:
                println("[ERRORE] Rispettare il formatto della data!");
                break;
            case MONTH_ERROR:
                println("[ERRORE] Il mese non e' valido! Dev'essere tra 1 e 12.");
                break;
            case DAY_ERROR:
                println("[ERRORE] Il giorno non e' valido! Dev'essere tra 1 e %d.", maxDay);
                break;
        }
        println("");
    } while (validationResult != DATE_OK);

    return date;
}
