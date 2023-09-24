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

char * charToOctal(char ch) {
    int digits = 0;
    for (char temp = ch; temp != 0; temp /= 8) digits++; 

    char * string = malloc(digits + 1); // +1 for null terminator

    for (int i = digits - 1; i >= 0; i--) {
        string[i] = (char)('0' + (ch % 8));
        ch /= 8;
    }

    return string;
}

char * charToHex(char ch) {
    int digits = 0;
    for (char temp = ch; temp != 0; temp /= 16) digits++; 

    char * string = malloc(digits + 1); // +1 for null terminator

    for (int i = digits - 1; i >= 0; i--) {
        int num = ch % 16;

        if (num >= 10) {
            num -= 10;
            string[i] = (char)('A' + num);
        } else {
            string[i] = (char)('0' + num);
        }

        ch /= 16;
    }

    return string;
}

char ** convertString(char string[], int type) {
    const int length = (int) strlen(string);
    char ** converts = malloc((length + 1) * sizeof(char*)); // length + 1 where the +1 is for null

    for (int i = length - 1; i >= 0; i--) {
        char * converted;

        switch (type) {
            case BINARY_TYPE:
                converted = charToBinary(string[i]);
                break;
            case OCTAL_TYPE:
                converted = charToOctal(string[i]);
                break;
            case HEX_TYPE:
            default:
                converted = charToHex(string[i]);
        }

        converts[i] = converted;
    }

    return converts;
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
