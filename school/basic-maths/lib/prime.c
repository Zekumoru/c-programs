#include "basicmaths.h"
#include <stdbool.h>

bool prime(int n) {
    int halfN = divide(n, 2);
    
    for (int i = 2; i <= halfN; i++) {
        if (modulus(n, i) == 0) {
            return false;
        }
    }

    return true;
}
