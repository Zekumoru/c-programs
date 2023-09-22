#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "conversions.h"

char * charToBinary(char ch) {
    char * bin = malloc(9);

    for (int i = 7, j = 0; i >= 0; i--, j++) {
        char shifted = ch >> j;
        int bit = (ch & shifted) != 0;
        bin[i] = bit == 0 ? '0' : '1';
    }

    return bin;
}

char ** strToBinary(char string[]) {
    const int length = getStrLength(string);
    char ** binaries = malloc(length * sizeof(char*));

    // for (int i = 0; i < length; i++) {

    // }
}