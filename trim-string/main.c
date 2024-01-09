#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int AVG_WPM = 130;

int main(int argc, char **argv) {
    FILE *fp;

    if (argc <= 1) {
        printf("Error: Missing file argument\n");
        return -1;
    }

    const char *filename = argv[2];

    fp = fopen(filename, "r");

    if (!fp) {
        printf("Error: file does not exist");
        return -1;
    }

    int count = 0;
    bool consumed = false;
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\r') {
            consumed = false;
        } else {
            if (!consumed) count++;
            consumed = true;
        }
    }

    printf("Total words: %d\n", count);
    printf("It can be read in: %.2f minutes\n", count / (float) AVG_WPM);

    return 0;
}
