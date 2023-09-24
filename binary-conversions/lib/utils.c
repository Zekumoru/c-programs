#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "utils.h"

char * getLineInput() {
    char ch;
    int length = 1;
    int allocLength = 2;
    char * string = malloc(length);
    
    while ((ch = getchar()) != '\n' && ch != EOF) {
        length++;
        string[length - 2] = ch;

        // Memory reallocation of O(n log n)
        if (length >= allocLength) {
            string = (char*) realloc(string, allocLength);
            allocLength *= 2;
        }
    }

    if (length == 1) {
        return string;
    }

    // Allocate a new char pointer string with the actual length
    char * returnString = malloc(length);
    memcpy(returnString, string, length);
    free(string);

    return returnString;
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

void * reallocateArray(void* arr, int length, int* allocLength) {
    char isToAllocate = FALSE;

    while (length >= *allocLength) {
        *allocLength *= 2;
        isToAllocate = TRUE;
    }

    if (!isToAllocate) return arr;

    return realloc(arr, *allocLength);
}

char * stringifyIntPArray(int** intPArray) {
    int allocLength = 1; 
    int length = allocLength;
    char * string = malloc(allocLength);

    for (int i = 0; intPArray[i] != NULL; i++) {
        int num = intPArray[i][0];
        // get how many digits there are inside 'num' plus the null terminator
        int numLength = snprintf(NULL, 0, "%d", num) + 1;
        length += numLength;
        if (intPArray[i + 1] == NULL) length--;

        char * numString = malloc(numLength);
        snprintf(numString, numLength, "%d", num);

        string = (char*) reallocateArray(string, length, &allocLength);

        strcat(string, numString);
        if (intPArray[i + 1] != NULL) strcat(string, " ");
    }

    // Allocate a new char pointer string with the actual length
    char * returnString = malloc(length);
    memcpy(returnString, string, length);
    free(string);

    return returnString;
}

void freeCharPArray(char** charPArray) {
    const int size = getCharPArrSize(charPArray);

    for (int i = size - 1; i >= 0; i--) {
        free(charPArray[i]);
    }

    free(charPArray);
}

void freeIntPArray(int** intPArray) {
    for (int i = 0; intPArray[i] != NULL; i++) {
        free(intPArray[i]);
    }

    free(intPArray);
}
