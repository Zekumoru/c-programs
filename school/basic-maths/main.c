#include <stdio.h>
#include "lib/basicmaths.h"

int main() {
    printf("%d\n", divide(10, 3));
    printf("%d\n", divide(-10, 3));
    printf("%d\n", divide(10, -3));
    printf("%d\n", divide(-10, -3));

    return 0;
}
