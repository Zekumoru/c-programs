#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "conversions.h"

char * charToBinary(char ch) {
    char * bin = malloc(ASCII_STRING_SIZE);

    //  -2 because of the null terminator character and end of string
    for (int i = ASCII_STRING_SIZE - 2, j = 0; i >= 0; i--, j++) {
        char shifted = ch >> j;
        int bit = shifted & 1;
        bin[i] = bit == 0 ? '0' : '1';
    }

    return bin;
}

char ** strToBinaries(char string[]) {
    const int length = (int) strlen(string);
    char ** binaries = malloc((length + 1) * sizeof(char*)); // length + 1 where the +1 is for null

    for (int i = length - 1; i >= 0; i--) {
        binaries[i] = charToBinary(string[i]);
    }

    return binaries;
}

int ** strToDecimals(char string[]) {
    const int length = (int) strlen(string);
    int ** decimals = malloc((length + 1) * sizeof(int*));

    for (int i = length - 1; i >= 0; i--) {
        decimals[i] = malloc(sizeof(int));
        decimals[i][0] = (int) string[i];
    }

    return decimals;
}
