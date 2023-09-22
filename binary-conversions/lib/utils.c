#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "utils.h"

int getStrLength(char string[]) {
    int length = 0;
    while (string[length] != '\0') length++;
    return length;
}

int getCharPArrSize(char** charPArray) {
    int size = 0;
    while (charPArray[size] != NULL) size++;
    return size;
}

char * stringifyBinaries(char** binaries) {
    const int size = getCharPArrSize(binaries);
    const int strLength = ASCII_STRING_SIZE * size + size; // +size for spaces between binaries and for the null terminator
    
    char * string = malloc(strLength);
    
    int stringPos = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < ASCII_STRING_SIZE - 1; j++, stringPos++) {
            string[stringPos] = binaries[i][j];
        }

        if ((i - 1) != size) {
            string[stringPos] = ' ';
            stringPos++;
        }
    }

    return string;
}

void freeCharPArray(char** charPArray) {
    const int size = getCharPArrSize(charPArray);

    for (int i = size - 1; i >= 0; i--) {
        free(charPArray[i]);
    }

    free(charPArray);
}
