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

void * reallocateArray(void* arr, int length, int* allocLength) {
    char isToAllocate = FALSE;

    while (length >= *allocLength) {
        *allocLength *= 2;
        isToAllocate = TRUE;
    }

    if (!isToAllocate) return arr;

    return realloc(arr, *allocLength);
}

char * fixStringAlloc(char* string, int length) {
    // Allocate a new char pointer string with the actual length
    char * fixedString = malloc(length);
    memcpy(fixedString, string, length - 1);
    free(string);

    return fixedString;
}

char * stringifyCharPArray(char** charPArray) {
    if (charPArray[0] == NULL) return NULL;

    int allocLength = 1;
    int length = allocLength;
    char * string = malloc(allocLength);

    for (int i = 0; charPArray[i] != NULL; i++) {
        char * item = charPArray[i];
        int itemLength = strlen(item) + 1;
        if (charPArray[i + 1] == NULL) length--;

        length += itemLength;
        string = (char*) reallocateArray(string, length, &allocLength);

        strcat(string, item);
        if (charPArray[i + 1] != NULL) strcat(string, " ");
    }

    return fixStringAlloc(string, length);
}

char * stringifyIntPArray(int** intPArray) {
    if (intPArray[0] == NULL) return NULL;

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

    return fixStringAlloc(string, length);
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
