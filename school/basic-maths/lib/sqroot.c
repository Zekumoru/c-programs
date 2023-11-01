#include "basicmaths.h"
#define NUM_OF_ITERATION 3 // higher iteration -> more precise

int sqroot(int n) {
    if (n < 0) return -1;
    if (n == 0) return 0;

    int result = n;

    for (int i = 0; i < NUM_OF_ITERATION; i++) {
        result = divide(result + divide(n, result), 2);
    }

    return result;
}
