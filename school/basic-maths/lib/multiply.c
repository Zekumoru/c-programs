#include "basicmaths.h"
#include <stdbool.h>

int multiply(int a, int b) {
    int result = 0;
    bool negFlag = b < 0;

    if (negFlag) b = -b;
    
    for (int i = 0; i < b; i++) {
        result += (negFlag)? -a : a;
    }

    return result;
}
