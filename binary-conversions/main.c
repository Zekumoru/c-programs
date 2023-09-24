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
    freeIntPArray(decimals);

    printf("Octal: ");
    printStrToOctal(input);
    printf("\n");

    printf("Hex: ");
    printStrToHex(input);
    printf("\n");

    char ** binaries = strToBinaries(input);
    printf("Binary: %s\n", stringifyBinaries(binaries));
    freeCharPArray(binaries);

    free(input);
    
    return 0;
}
