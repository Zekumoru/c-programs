#include <stdio.h>
#include <stdbool.h>

void execFor(int, int);
void execWhile(int, int);
void execDoWhile(int, int);

int main()
{
    int init = 0;
    int max = 0;
    execFor(init, max);
    execWhile(init, max);
    execDoWhile(init, max);
    return 0;
}

void execFor(int init, int max)
{
    for (int i = init; i < max; i++) {
        printf("for: %d\n", i);
    }
}

void execWhile(int init, int max)
{
    int i = init;
    while (i < max) {
        printf("while: %d\n", i);
        i++;
    }
}

bool doWhileCond(int value, int max)
{
    return value < max;
}

void execDoWhile(int init, int max)
{
    int i = init;
    do {
        if (!doWhileCond(i, max)) break;
        printf("do-while: %d\n", i);
        i++;
    } while (doWhileCond(i, max));
}
