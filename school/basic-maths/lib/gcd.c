#include "basicmaths.h"

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = modulus(a, b);
        a = temp;
    }

    return a;
}
