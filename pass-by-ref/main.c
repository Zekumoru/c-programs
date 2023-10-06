#include <stdio.h>
#include <stdarg.h>

void println(const char * fmt, ...) {
    va_list args;
    va_start(args, fmt);

    vprintf(fmt, args);
    printf("\n");

    va_end(args);
}

/* C++
int passByReference(int &num) {
    num++;
}
*/

#define passByReference(x) (x = passByReference_Internal(x))
int passByReference_Internal(int num) {
    num++;
    return num;
}

int main() {
    int num;

    printf("Enter number: ");
    scanf(" %d", &num);

    passByReference(num);
    
    println("Number: %d", num);

    return 0;
}
