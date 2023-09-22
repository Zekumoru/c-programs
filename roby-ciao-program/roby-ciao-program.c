#include <stdio.h>

int main()
{
    // int c=67;
    // int i=73;
    // int a=65;
    // int o=79;
    // int e=33;
    //char x='c';
    //char y='i';
    //char z='a';
    //char j='o';
    //char k='!';
    char cbin[8]="01000011";
    char ibin[8]="a1001001";
    char abin[8]="01000001";
    char obin[8]="01001111";
    char ebin[8]="00100001";
    
    // printf("%c%c%c%c%c (utilizzata variabile 'int')", c, i, a, o, e);
                                               
    // printf("\nDEC: %d, %d, %d, %d, %d", c, i, a, o, e); 
    // printf("\nOCT: %o, %o, %o, %o, %o", c, i, a, o, e); 
    // printf("\nHEX: %x, %x, %x, %x, %x", c, i, a, o, e);

    printf("%c", cbin[8]);
    // printf("BIN: %s", cbin);
    printf("\n\n");

    return 0;
}


