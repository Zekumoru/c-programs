#include <stdio.h>
#include "lib/utils.h"

int main(int argc, char** argv) {
    float num1;
    float num2;

    printf("Enter first number: ");
    num1 = getFloatComma();

    printf("Enter second number: ");
    num2 = getFloatComma();

    println("Their sum is: %.2f", num1 + num2);

    return 0;
}
