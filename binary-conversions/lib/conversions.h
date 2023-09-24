#ifndef CONVERSIONS_H
#define CONVERSIONS_H
#define BINARY_TYPE 0
#define OCTAL_TYPE 1
#define HEX_TYPE 2

char * charToBinary(char);
char * charToOctal(char);
char * charToHex(char);

char ** convertString(char[], int type);

int ** strToDecimals(char[]);

#endif
