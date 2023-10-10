#include <ncurses.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#define THRESHOLD 0.000001

void printTerm(double c, const char * t) {
    if (c > -THRESHOLD && c < THRESHOLD) {
        printw("____");
    } else {
        printw("%.2lf", c);
    }
    printw("%s", t);
}

void handleInput(int input, int curTerm, double* a, double* b, double* c) {
    double digit = input - '0';
    if (curTerm == 0) {
        *a = digit;
    } else if (curTerm == 1) {
        *b = digit;
    } else {
        *c = digit;
    }
}

void calculate(double a, double b, double c) {
    double delta = pow(b, 2) - 4 * a * c;

    if (delta < 0) {
        printw("No solution exists.");
        return;
    }

    if (delta > -THRESHOLD && delta < THRESHOLD) {
        double solution = - b / (2 * a);
        printw("1 Solution: %.2lf", solution);
        return;
    }

    double s1 = - (b + sqrt(delta)) / (2 * a);
    double s2 = - (b - sqrt(delta)) / (2 * a);
    printw("2 Solutions: %.2lf and %.2lf", s1, s2);
}

int main() {
    initscr();
    keypad(stdscr, true);

    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    int aXPos = 0;
    int bXPos = 0;
    int cXPos = 0;
    int eqYPos = 0;
    int curTerm = 0;
    bool toCalculate = false;

    int input;
    while (true) {
        clear();

        eqYPos = getcury(stdscr);
        aXPos = getcurx(stdscr);
        printTerm(a, "x^2");
        printw(" + ");

        bXPos = getcurx(stdscr);
        printTerm(b, "x");
        printw(" + ");
        
        cXPos = getcurx(stdscr);
        printTerm(c, "");
        printw(" = 0");

        if (toCalculate) {
            printw("\n");
            calculate(a, b, c);
        }

        printw("\n\n'Q' to quit. 'C' to calculate.");

        if (curTerm == 0) {
            move(eqYPos, aXPos);
        } else if (curTerm == 1) {
            move(eqYPos, bXPos);
        } else {
            move(eqYPos, cXPos);
        }

        input = getch();

        toCalculate = tolower(input) == 'c';

        if (tolower(input) == 'q') {
            break;
        }

        if (input == KEY_RIGHT) {
            curTerm++;
            if (curTerm >= 3) curTerm = 0;
        } else if (input == KEY_LEFT) {
            curTerm--;
            if (curTerm < 0) curTerm = 2;
        }

        if (isdigit(input)) {
            handleInput(input, curTerm, &a, &b, &c);
        }
    }

    endwin();

    return 0;
}