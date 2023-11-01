#include "basicmaths.h"

int power(int a, int b) {
    int result = a;

    if (b == 0) return 1;

    for (int i = 1; i < b; i++) {
        result = multiply(result, a);
    }

    return result;
}
