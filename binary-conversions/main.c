#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/conversions.h"
#include "lib/utils.h"

int main() {
    char * input;
    
    printf("Enter string: ");
    input = getLineInput();

    printf("\n");

    int ** decimals = strToDecimals(input);
    printf("Decimal: %s\n", stringifyIntPArray(decimals));

    char ** octals = convertString(input, OCTAL_TYPE);
    printf("Octal: %s\n", stringifyCharPArray(octals));
    
    char ** hexes = convertString(input, HEX_TYPE);
    printf("Hex: %s\n", stringifyCharPArray(hexes));

    char ** binaries = convertString(input, BINARY_TYPE);
    printf("Binary: %s\n", stringifyCharPArray(binaries));

    freeIntPArray(decimals);
    freeCharPArray(binaries);
    freeCharPArray(octals);
    freeCharPArray(hexes);
    free(input);
    
    return 0;
}
