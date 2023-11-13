#include "playground.h"
#include <stdio.h>

int dblWordToInt(const char * doubleWord)
{
    int num = 0;
    for (int i = 3; i >= 0; i--) {
        num += doubleWord[i];
        if (i != 0) num <<= 8;
    }
    return num;
}

void printIntArray(const char * varName, int array[], int size)
{
    printf("int %s[] = { ", varName);
    for (size_t i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i != (size - 1)) printf(", ");
    }
    printf(" };\n");
}

void testArray()
{
    size_t size = 5;
    int numbers[] = { 257, 2, 3, 4, 5 };
    const int index = 3;

    printIntArray("numbers", numbers, size);
    printf("'Base address' refers to the base address of numbers[]\n");

    // int number = *(numbers + index * sizeof(int));
    int number = *(numbers + index);

    printf("\n");
    printf("Base address:\t\t\t %p\n", numbers);
    printf("Base address + 1:\t\t %p\n", numbers + 1);
    printf("Base address + 2 * sizeof(int):\t %p\n", numbers + 2 * sizeof(int));
    printf("Base address + 8:\t\t %p\n", numbers + 8);

    char * pNumbers = (char*)numbers;

    printf("\n");
    printf("Cast base int arr to char*\n");
    printf("Base address:\t\t\t %p\n", pNumbers);
    printf("Base address + 1:\t\t %p\n", pNumbers + 1);
    printf("Base address + 3:\t\t %p\n", pNumbers + 3);
    printf("[Base address + 3]:\t\t %d\n", *(pNumbers + 0));
}
