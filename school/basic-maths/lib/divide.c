#include "basicmaths.h"

int divide(int a, int b) {
    int result;
    bool negFlag = (a < 0)^(b < 0);

    if (a < 0) a = -a;
    if (b < 0) b = -b;

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
