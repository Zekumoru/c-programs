#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/conversions.h"
#include "lib/utils.h"

int main() {
    printf("%s\n", stringifyBinaries(strToBinaries("ciao")));
    return 0;
}
