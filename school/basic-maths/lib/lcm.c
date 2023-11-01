#include "basicmaths.h"

int lcm(int a, int b) {
    return divide(multiply(a, b), gcd(a, b));
}
