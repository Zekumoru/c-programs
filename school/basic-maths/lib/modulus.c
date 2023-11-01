#include "basicmaths.h"

int modulus(int a, int b) {
    int result = divide(a, b);
    return a - multiply(result, b);
}
