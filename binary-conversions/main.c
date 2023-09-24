#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/conversions.h"
#include "lib/utils.h"
#include "lib/print-utils.h"

int main() {
    char * input;
    
    printf("Enter string: ");
    input = getLineInput();

    printf("\n");

    int ** decimals = strToDecimals(input);
    printf("Decimal: %s\n", stringifyIntPArray(decimals));

    char ** octals = strToOctals(input);
    printf("Octal: %s\n", stringifyCharPArray(octals));

    printf("Hex: ");
    printStrToHex(input);
    printf("\n");

    char ** binaries = strToBinaries(input);
    printf("Binary: %s\n", stringifyCharPArray(binaries));

    freeIntPArray(decimals);
    freeCharPArray(binaries);
    freeCharPArray(octals);
    free(input);
    
    return 0;
}
