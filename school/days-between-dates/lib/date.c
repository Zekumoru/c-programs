#include "date.h"
#include "utils.h"
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

Date *createDate(int year, int month, int day)
{
    Date *date = malloc(sizeof(Date));
    date->year = year;
    date->month = month;
    date->day = day;
    return date;
}

int daysSinceStartOfYear(Date *date)
{
    // Totals days assuming each month has 31 days 
    // minus 2 days because of February
    // not minus 3 days since the other 1 day is
    // calculated with diffFH
    int days = date->month * 31 + date->day;
    if (date->month > FEBRUARY) days -= 2 - (isLeapYear(date->year)? 1 : 0);

    // diff first half of year
    // basically how many 30-days month before JULY
    int diffFH = date->month;
    if (date->month > JULY) diffFH = JULY;
    diffFH /= 2;

    // diff second half of year
    // basically how many 30-days month after AUGUST
    int diffSH = date->month - AUGUST;
    if (diffSH < 0) diffSH = 0;
    diffSH /= 2;

    return days - (diffFH + diffSH);
}

int countTotalLeapYears(int year)
{
    return (year / 400) - (year / 100) + (year / 4);
}

int countLeapYearsBetween(int y1, int y2)
{
    return abs(countTotalLeapYears(y1) - countTotalLeapYears(y2));
}

bool shouldRemoveLeapYear(Date *d1, Date* d2)
{
    return !isLeapYear(d1->year) && isLeapYear(d2->year) && d1->year < d2->year && d2->month == FEBRUARY && d2->day < 29;
}

int countDays(Date *d1, Date *d2)
{
    int days1 = daysSinceStartOfYear(d1);
    int days2 = daysSinceStartOfYear(d2);
    int days = abs(d1->year - d2->year) * 365;

    if (d2->year > d1->year) days += days2 - days1; 
    else if (d1->year > d2->year) days += days1 - days2;
    else days += abs(days1 - days2);

    int leapYearsBetween = countLeapYearsBetween(d1->year, d2->year);
    if (shouldRemoveLeapYear(d1, d2) || shouldRemoveLeapYear(d2, d1)) {
        leapYearsBetween--;
    }

    return days + leapYearsBetween;
}

bool isLeapYear(int year)
{
    return (year % 400) == 0 || (year % 100 && (year % 4) == 0);
}

bool isdatefmt(char c)
{
    return c == 'y' || c == 'm' || c == 'd';
}

int validateDateFmt(const char *input, const char* fmt, Date **out, int *_maxDay)
{
    if (strlen(input) != strlen(fmt)) {
        return LENGTH_ERROR;
    }

    Date *date = createDate(0, 0, 0);

    for (size_t i = 0; i < strlen(fmt); i++) {
        if (isdigit(input[i]) && isdatefmt(fmt[i])) {
            int digit = input[i] - '0';
            if (fmt[i] == 'y') {
                date->year *= 10;
                date->year += digit;
            } else if (fmt[i] == 'm') {
                date->month *= 10;
                date->month += digit;
            } else if (fmt[i] == 'd') {
                date->day *= 10;
                date->day += digit;
            }
            continue;
        }
        if (input[i] == fmt[i] && fmt[i] == '/') {
            continue;
        }
        return FORMAT_ERROR;
    }
    date->month--;

    if (date->month < JANUARY || date->month > DECEMBER) {
        return MONTH_ERROR;
    }
    
    int maxDay;
    if (date->month == FEBRUARY) {
        maxDay = isLeapYear(date->year)? 29 : 28;
    } else if (date->month % 2 && date->month < JULY) {
        maxDay = 30;
    } else if (date->month % 2 == 0 && date->month > AUGUST) {
        maxDay = 30;
    } else {
        maxDay = 31;
    }
    
    *_maxDay = maxDay;
    if (date->day < 1 || date->day > maxDay) {
        return DAY_ERROR;
    }

    if (out != NULL) *out = date;
    return DATE_OK;
}
