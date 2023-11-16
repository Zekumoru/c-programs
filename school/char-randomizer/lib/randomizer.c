#include "randomizer.h"
#include <stdlib.h>
#include <time.h>

const char CHAR_START = ' ';
const char CHAR_END = '~';
const size_t CHAR_TOTAL = CHAR_END - CHAR_START + 1;

int randbetween(int min, int max)
{
    return rand() % (max - min) + min;
}

char randomize()
{
    return randbetween(CHAR_START, CHAR_END + 1);
}

int getTableKey(char ch)
{
    return ch - CHAR_START;
}

int *generateCountTable(size_t generateN)
{
    int *countTable = malloc(CHAR_TOTAL * sizeof(int));
    for (size_t i = 0; i < CHAR_TOTAL; i++) countTable[i] = 0;

    for (int i = 0; i < generateN; i++) {
        char ch = randomize();
        countTable[getTableKey(ch)]++;
    }

    return countTable;
}
