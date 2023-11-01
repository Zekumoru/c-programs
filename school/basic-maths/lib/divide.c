#include "basicmaths.h"

int divide(int a, int b) {
    int result;
    bool negFlag = false;

    if (a < 0 && b < 0) {
        a = multiply(a, -1);
        b = multiply(b, -1);
    } else if (a < 0) {
        a = multiply(a, -1);
        negFlag = true;
    } else if (b < 0) {
        b = multiply(b, -1);
        negFlag = true;
    }

    if (b == 0) {
        if (negFlag) return NEG_INFINITY;
        return INFINITY;
    }
    
    for (result = 0; a >= b; a -= b) {
        if (negFlag) result--;
        else result++;
    }

    return result;
}
