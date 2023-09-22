#include <stdio.h>
#include "utils.h"

void printStrToOctal(char string[]) {
    const int length = getStrLength(string);

    for (int i = 0; i < length; i++) {
        printf("%o", string[i]);
        if ((i - 1) != length) printf(" ");
    }
}

void printStrToDecimals(char string[]) {
    const int length = getStrLength(string);

    for (int i = 0; i < length; i++) {
        printf("%d", string[i]);
        if ((i - 1) != length) printf(" ");
    }
}

void printStrToHex(char string[]) {
    const int length = getStrLength(string);

    for (int i = 0; i < length; i++) {
        printf("%X", string[i]);
        if ((i - 1) != length) printf(" ");
    }
}