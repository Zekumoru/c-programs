#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * getLineInput();

int main() {
    char * string;
    
    printf("Enter string: ");
    string = getLineInput();
    
    printf("%s\n", string);
    printf("The length of the string is %d\n", (int) strlen(string));

    return 0;
}

char * getLineInput() {
    char ch;
    int length = 1;
    int allocLength = 2;
    char * string = malloc(length);
    
    while ((ch = getchar()) != '\n' && ch != EOF) {
        length++;
        string[length - 2] = ch;

        // Memory reallocation of O(n log n)
        if (length >= allocLength) {
            string = (char*) realloc(string, allocLength);
            allocLength *= 2;
        }
    }

    if (length == 1) {
        return string;
    }

    // Allocate a new char pointer string with the actual length
    char * returnString = malloc(length);
    memcpy(returnString, string, length);
    free(string);

    return returnString;
}
