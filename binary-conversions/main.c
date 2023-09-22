#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/conversions.h"
#include "lib/utils.h"
#include "lib/print-utils.h"

int main() {
    char input[200];
    
    printf("Enter string: ");
    scanf(" %[^\n]s", input);

    printf("\n");

    printf("Decimal: ");
    printStrToDecimals(input);
    printf("\n");

    printf("Octal: ");
    printStrToOctal(input);
    printf("\n");

    printf("Hex: ");
    printStrToHex(input);
    printf("\n");

    char ** binaries = strToBinaries(input);
    printf("Binary: %s\n", stringifyBinaries(binaries));
    freeCharPArray(binaries);
    
    return 0;
}
