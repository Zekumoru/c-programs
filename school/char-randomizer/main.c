#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib/randomizer.h"

int main()
{
    srand(time(NULL));

    int *countTable = generateCountTable(10000);

    char input;
    printf("Enter character to see its count: ");
    scanf(" %c", &input);

    printf("'%c' occurred %d times in 10K generated characters!\n", input, countTable[getTableKey(input)]);

    free(countTable);

    return 0;
}
