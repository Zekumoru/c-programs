#include <stdio.h>

void *refer(void* v);

int main()
{
    int num = 50;
    printf("Value: %d\n", *(int*)(refer(&num)));
    return 0;
}

void *refer(void* v)
{
    return v;
}
