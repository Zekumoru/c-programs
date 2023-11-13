#include <stdio.h>
#include "lib/playground.h"

void printSomething();

int main()
{
    testArray();
    printSomething();

    return 0;
}

void printSomething()
{
    int numbers[] = {
        dblWordToInt("Hell"),
        dblWordToInt("o wo"),
        dblWordToInt("rld!")
    };
    
    printf("\n");
    printf("Contain \"Hello world!\" in int[]\n");
    printIntArray("numbers", numbers, 3);
    printf("\n");

    char* pNumbers = (char*)numbers;
    for (size_t i = 0; i < 12; i++) {
        char* current = pNumbers + i;
        printf("numbers + %p: %c\n", current, *current);
    }
}
