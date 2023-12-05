#include "generator.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mergesort.h"

const int LOWERCASE_ALPHA_CHARS = 1 << 0;
const int UPPERCASE_ALPHA_CHARS = 1 << 1;
const int DIGIT_CHARS = 1 << 2;
const int SPECIAL_CHARS = 1 << 3;
const int ALPHA_CHARS = LOWERCASE_ALPHA_CHARS | UPPERCASE_ALPHA_CHARS;
const int ALNUM_CHARS = ALPHA_CHARS | DIGIT_CHARS;
const int ALL_PRINTABLE_CHARS = ALNUM_CHARS | SPECIAL_CHARS;

char *standardizeIgnoreChars(const char _ignoreChars[])
{
    if (_ignoreChars == NULL) return NULL;

    // sort ignoreChars to achieve O(n log n) time complexity
    // when ignoring characters by using an ignore pointer
    int length = strlen(_ignoreChars);
    char *ignoreChars = malloc(length + 1);
    strcpy(ignoreChars, _ignoreChars);
    ignoreChars[length] = '\0';
    mergesort(ignoreChars, length);

    // remove duplicates
    int lp; // left pointer
    int rp; // right pointer
    char prev;
    for (lp = 0, rp = 1; rp < length; rp++) {
        prev = ignoreChars[rp - 1];
        if (ignoreChars[lp] == ignoreChars[rp]) {
            continue;
        }
        
        lp++;
        if ((rp - lp) > 1 && prev != ignoreChars[rp]) {
            ignoreChars[lp] = ignoreChars[rp];
        }
    }

    ignoreChars = (char*) realloc(ignoreChars, lp + 2);
    ignoreChars[lp + 1] = '\0';
    return ignoreChars;
}

bool generateString_addRange(
    const char ch, const char start, const char end,
    char *charTable, int *tableSize,
    const int charTypes, const int charType
) {
    if (ch < start || ch > end) {
        return false;
    }
    
    if (charTypes & charType) {
        charTable[*tableSize] = ch;
        (*tableSize)++;
    }

    return true;
}

void generateString_initCharTable(char **charTable, int *tableSize, const int charTypes, const char *ignoreChars)
{
    const char START_CHAR = 32;
    const char END_CHAR = 126;

    *charTable = malloc(END_CHAR - START_CHAR + 1);
    *tableSize = 0;

    size_t ignorePointer = 0;
    for (char ch = START_CHAR; ch <= END_CHAR; ch++) {
        if (ignoreChars != NULL && ch == ignoreChars[ignorePointer]) {
            ignorePointer++;
            continue;
        }
        
        if (generateString_addRange(ch, '0', '9', *charTable, tableSize, charTypes, DIGIT_CHARS)
            || generateString_addRange(ch, 'A', 'Z', *charTable, tableSize, charTypes, UPPERCASE_ALPHA_CHARS)
            || generateString_addRange(ch, 'a', 'z', *charTable, tableSize, charTypes, LOWERCASE_ALPHA_CHARS)
        ) {
            continue;
        }

        if (charTypes & SPECIAL_CHARS) {
            (*charTable)[*tableSize] = ch;
            (*tableSize)++;
        }
    }
}

char *generateString(const int length, const int charTypes, const char _ignoreChars[])
{
    // time complexity O(n log n) where n is the length
    // of the '_ignoreChars' string
    char *ignoreChars = standardizeIgnoreChars(_ignoreChars);

    char *charTable;
    int tableSize;
    // time complexity O(1) since it does not depend
    // on the length of the 'ignoreChars' string
    generateString_initCharTable(&charTable, &tableSize, charTypes, ignoreChars);

    // generation of the random string is of time
    // complexity O(n) where n is the parameter 'length'
    char *generated;
    if (tableSize == 0) {
        generated = malloc(1);
        generated[0] = '\0';
    } else {
        generated = malloc(length + 1);
        for (int i = 0; i < length; i++) {
            generated[i] = charTable[rand() % tableSize];
        }
        generated[length] = '\0';
    }

    free(charTable);
    free(ignoreChars);

    return generated;
}
