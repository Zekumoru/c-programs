#include <stdio.h>
#include <stdlib.h>

char * getLineInput();
int getStrLength(char[]);

int main() {
    char * string;
    
    printf("Enter string: ");
    string = getLineInput();
    
    printf("%s\n", string);
    printf("The length of the string is %d\n", getStrLength(string));

    return 0;
}

char * getLineInput() {
    char ch;
    int length = 2;
    char* string = malloc(length);
    
    while ((ch = getchar()) != '\n' && ch != EOF) {
        string[length - 2] = ch;
        string = (char*) realloc(string, length);
        length++;
    }

    return string;
}

int getStrLength(char string[]) {
    int length = 0;
    while (string[length] != '\0') length++;
    return length;
}
