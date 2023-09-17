#include <stdio.h>
#include <ctype.h>

void printLn(char[]);
int getStrLength(char[]);
void printLetterHelper(int, char, char[], char[], char[], char[], char[]);
void printLetter(char, int);
void printString(char[]);

int main()
{
    printString("Hello World!");
    return 0;
}

void printLetterHelper(int index, char ch, char first[], char second[], char third[], char fourth[], char fifth[]) {
    if (index >= 5) {
        printf("Error! Index %d out of bounds while printing %c!", index, ch);
        return;
    }
    
    if (index < 0 || index == 0) printf("%s", first);
    if (index < 0 || index == 1) printf("%s", second);
    if (index < 0 || index == 2) printf("%s", third);
    if (index < 0 || index == 3) printf("%s", fourth);
    if (index < 0 || index == 4) printf("%s", fifth);
}

void printLetter(char ch, int index) {
    switch (tolower(ch)) {
        case 'a': 
            printLetterHelper(index, 'A', " AAA ", "A   A", "AAAAA", "A   A", "A   A");
            break;
        case 'b':
            printLetterHelper(index, 'B', "BBBB ", "B   B", "BBBB ", "B   B", "BBBB ");
            break;
        case 'c':
            printLetterHelper(index, 'C', " CCCC", "C    ", "C    ", "C    ", " CCCC");
            break;
        case 'd':
            printLetterHelper(index, 'D', "DDDD ", "D   D", "D   D", "D   D", "DDDD ");
            break;
        case 'e':
            printLetterHelper(index, 'E', "EEEEE", "E    ", "EEE  ", "E    ", "EEEEE");
            break;
        case 'f':
            printLetterHelper(index, 'F', "FFFFF", "F    ", "FFF  ", "F    ", "F    ");
            break;
        case 'g':
            printLetterHelper(index, 'G', " GGGG", "G    ", "G  GG", "G   G", " GGGG");
            break;
        case 'h':
            printLetterHelper(index, 'H', "H   H", "H   H", "HHHHH", "H   H", "H   H");
            break;
        case 'i':
            printLetterHelper(index, 'I', "IIIII", "  I  ", "  I  ", "  I  ", "IIIII");
            break;
        case 'j':
            printLetterHelper(index, 'J', "   JJ", "    J", "    J", "J   J", " JJJJ");
            break;
        case 'k':
            printLetterHelper(index, 'K', "K   K", "K KK ", "KK   ", "K KK ", "K   K");
            break;
        case 'l':
            printLetterHelper(index, 'L', "L    ", "L    ", "L    ", "L    ", "LLLLL");
            break;
        case 'm':
            printLetterHelper(index, 'M', "M   M", "MM MM", "M M M", "M   M", "M   M");
            break;
        case 'n':
            printLetterHelper(index, 'N', "N   N", "NN  N", "N N N", "N  NN", "N   N");
            break;
        case 'o':
            printLetterHelper(index, 'O', " OOO ", "O   O", "O   O", "O   O", " OOO ");
            break;
        case 'p':
            printLetterHelper(index, 'P', "PPPP ", "P   P", "PPPP ", "P    ", "P    ");
            break;
        case 'q':
            printLetterHelper(index, 'Q', " QQQ ", "Q   Q", "Q   Q", "Q  Q ", " QQ Q");
            break;
        case 'r':
            printLetterHelper(index, 'R', "RRRR ", "R   R", "RRRR ", "R  RR", "R   R");
            break;
        case 's':
            printLetterHelper(index, 'S', " SSSS", "S    ", " SSS ", "    S", "SSSS ");
            break;
        case 't':
            printLetterHelper(index, 'T', "TTTTT", "  T  ", "  T  ", "  T  ", "  T  ");
            break;
        case 'u':
            printLetterHelper(index, 'U', "U   U", "U   U", "U   U", "U   U", " UUU ");
            break;
        case 'v':
            printLetterHelper(index, 'V', "V   V", "V   V", "V   V", " V V ", "  V  ");
            break;
        case 'w':
            printLetterHelper(index, 'W', "W   W", "W   W", "W   W", "W W W", " W W ");
            break;
        case 'x':
            printLetterHelper(index, 'X', "X   X", " X X ", "  X  ", " X X ", "X   X");
            break;
        case 'y':
            printLetterHelper(index, 'Y', "Y   Y", "Y   Y", " Y Y ", "  Y  ", "  Y  ");
            break;
        case 'z':
            printLetterHelper(index, 'Z', "ZZZZZ", "   Z ", "  Z  ", " Z   ", "ZZZZZ");
            break;
        case '!':
            printLetterHelper(index, '!', " !!! ", " !!! ", " !!! ", "     ", " !!! ");
            break;
        case ' ':
            printLetterHelper(index, '?', "     ", "     ", "     ", "     ", "     ");
            break;
        default:
            printLetterHelper(index, ' ', "*****", "** **", "* * *", "** **", "*****");
    }

    if (ch == ' ') return;
    
    printLetterHelper(index, ' ', " ", " ", " ", " ", " ");
}

void printString(char string[]) {
    const int length = getStrLength(string);
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < length; j++) {
            printLetter(string[j], i);
        }

        printf("\n");
    }
}

void printLn(char string[]) {
    printf("%s\n", string);
}

int getStrLength(char string[]) {
    int length = 0;
    while (string[length] != '\0') length++;
    return length;
}
