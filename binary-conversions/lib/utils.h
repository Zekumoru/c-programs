#ifndef UTILS_H
#define UTILS_H
#define FALSE 0
#define TRUE 1

char * getLineInput();

char * stringifyBinaries(char**);
char * stringifyIntPArray(int**);

void freeCharPArray(char**);
void freeIntPArray(int**);

#endif
