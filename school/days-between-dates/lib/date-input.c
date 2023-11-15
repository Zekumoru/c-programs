#include "date-input.h"
#include <stdio.h>
#include <stdlib.h>
#include "date.h"
#include "utils.h"

const char *dateFormats[] = {
    "dd/mm/yyyy",
    "mm/dd/yyyy",
    "yyyy/mm/dd"
};

Date *getDateInput(const char *prompt, int fmtOption)
{
    Date *date;
    int validationResult;
    
    do {
        printf("%s [%s]: ", prompt, dateFormats[fmtOption]);
        char *input = getln();
        
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
        free(input);
    } while (validationResult != DATE_OK);

    return date;
}
