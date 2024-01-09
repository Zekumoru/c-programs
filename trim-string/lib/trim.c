#include "trim.h"
#include <stdlib.h>
#include <string.h>

char *trim(const char *str) {
    int lp = 0;
    int rp = strlen(str) - 1;

    while (str[lp] == ' ') lp++;
    while (str[rp] == ' ') rp--;

    // '   ok'
    //  01234
    int length = rp - lp + 1 + 1; // Another +1 for string terminator
    if (length < 0) length = 2;
    char *trimmed = malloc(length);
    
    int i;
    for (i = 0; lp <= rp; lp++, i++) {
        trimmed[i] = str[lp];
    }
    trimmed[i] = '\0';

    return trimmed;
}