#include "05-attr-and-colors.h"
#include <ncurses.h>
#include <stdarg.h>

void showAttributeWithText(attr_t attr, const char * fmt, ...);
void showAttributes();

void showColorWithText(short id, short fgColor, short bgColor, const char * fmt, ...);
void showColors();

short rgbToCursesColor(short rgb);
void showRGBColorWithText(short id, short fgRColor, short fgGColor, short fgBColor, short bgRColor, short bgGColor, short bgBColor, const char * fmt, ...);
void showRGBColors();

int program05() {
    initscr();

    showAttributes();
    showColors();

    printw("\nPress any key to show custom rgb colors.\n");
    printw("(This will override COLOR_WHITE and COLOR_BLACK, i.e., default color for background)\n");
    getch();

    showRGBColors();

    printw("\nPress any key to exit...");
    getch();
    endwin();

    return 0;
}

void showAttributes() {
    showAttributeWithText(A_NORMAL, "A_NORMAL on\n");
    showAttributeWithText(A_STANDOUT, "A_STANDOUT on\n");
    showAttributeWithText(A_REVERSE, "A_REVERSE on\n");
    showAttributeWithText(A_BLINK, "A_BLINK on\n");
    showAttributeWithText(A_DIM, "A_DIM on\n");
    showAttributeWithText(A_BOLD, "A_BOLD on\n");
    showAttributeWithText(A_PROTECT, "A_PROTECT on\n");
    showAttributeWithText(A_INVIS, "A_INVIS on\n");
    showAttributeWithText(A_ALTCHARSET, "A_ALTCHARSET on\n");
    showAttributeWithText(A_CHARTEXT, "A_CHARTEXT on\n");
    printw("\n");
}

void showAttributeWithText(attr_t attr, const char * fmt, ...) {
    va_list args;
    va_start(args, fmt);
    
    attron(attr);
    vw_printw(stdscr, fmt, args);
    attroff(attr);

    va_end(args);
}

void showColors() {
    /* The has_colors() subroutine indicates whether the 
     * terminal is a color terminal.
     * The can_change_color() subroutine indicates
     * whether the terminal is a color terminal on 
     * which colors can be redefined.
     * 
     * Source: https://www.ibm.com/docs/ssw_aix_72/c_bostechref/can_change_color.html#:~:text=The%20has_colors%20subroutine%20indicates%20whether,which%20colors%20can%20be%20redefined.
     */
    if (!has_colors()) {
        printw("Terminal does not support colors.\n");
        return;
    }

    start_color();

    showColorWithText(0, COLOR_BLACK, COLOR_WHITE, "FG: COLOR_BLACK | BG: COLOR_WHITE on\n");
    showColorWithText(1, COLOR_RED, COLOR_BLACK, "FG: COLOR_RED | BG: COLOR_BLACK on\n");
    showColorWithText(2, COLOR_GREEN, COLOR_BLACK, "FG: COLOR_GREEN | BG: COLOR_BLACK on\n");
    showColorWithText(3, COLOR_YELLOW, COLOR_BLACK, "FG: COLOR_YELLOW | BG: COLOR_BLACK on\n");
    showColorWithText(4, COLOR_BLUE, COLOR_BLACK, "FG: COLOR_BLUE | BG: COLOR_BLACK on\n");
    showColorWithText(5, COLOR_MAGENTA, COLOR_BLACK, "FG: COLOR_MAGENTA | BG: COLOR_BLACK on\n");
    showColorWithText(6, COLOR_CYAN, COLOR_BLACK, "FG: COLOR_CYAN | BG: COLOR_BLACK on\n");
    showColorWithText(7, COLOR_WHITE, COLOR_RED, "FG: COLOR_WHITE | BG: COLOR_RED on\n");
    printw("\n");
}

void showRGBColors() {
    if (!can_change_color()) {
        printw("Terminal does not support changing colors.\n");
        return;
    }

    showRGBColorWithText(
        8, // id
        44, 105, 184, // RGB foreground
        0, 0, 0, // RGB background
        "FG: RGB(44, 105, 184) | BG: RGB(0, 0, 0) on\n"
    );
    printw("\n");
}

void showColorWithText(short id, short fgColor, short bgColor, const char * fmt, ...) {
    va_list args;
    va_start(args, fmt);

    init_pair(id, fgColor, bgColor);
    showAttributeWithText(COLOR_PAIR(id), fmt, args);

    va_end(args);
}

void showRGBColorWithText(
    short id, 
    short fgRColor, short fgGColor, short fgBColor, 
    short bgRColor, short bgGColor, short bgBColor, 
    const char * fmt, ...
) {
    va_list args;
    va_start(args, fmt);

    init_color(
        COLOR_WHITE,
        rgbToCursesColor(fgRColor),
        rgbToCursesColor(fgGColor),
        rgbToCursesColor(fgBColor)
    );
    init_color(
        COLOR_BLACK,
        rgbToCursesColor(bgRColor),
        rgbToCursesColor(bgGColor),
        rgbToCursesColor(bgBColor)
    );
    showColorWithText(id, COLOR_WHITE, COLOR_BLACK, fmt, args);

    va_end(args);
}

short rgbToCursesColor(short rgb) {
    return rgb / 0.255;
}
