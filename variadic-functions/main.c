#include <stdio.h>
#include "lib/utils.h"

int main(int argc, char** argv) {
    int num1;
    int num2;

    printf("Enter first number: ");
    num1 = getInt();

    printf("Enter second number: ");
    num2 = getInt();

    println("Their sum is: %d", num1 + num2);

    return 0;
}
