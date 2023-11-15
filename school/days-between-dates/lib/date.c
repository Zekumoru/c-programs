#include "date.h"
#include "utils.h"
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

Date createDate(int year, int month, int day)
{
    return (Date){ year, month, day };
}

struct tm *dateToTm(Date date)
{
    struct tm *timeStruct;

    time_t raw = time(NULL);
    timeStruct = localtime(&raw);
    timeStruct->tm_year = date.year - 1900;
    timeStruct->tm_mon = date.month;
    timeStruct->tm_mday = date.day;

    return timeStruct;
}

int countDays(Date d1, Date d2)
{
    time_t t1 = mktime(dateToTm(d1));
    time_t t2 = mktime(dateToTm(d2));
    return (t1 - t2) / SEC_PER_DAY;
}

bool isLeapYear(int year)
{
    return (year % 400) == 0 || (year % 100 && (year % 4) == 0);
}

bool isdatefmt(char c)
{
    return c == 'y' || c == 'm' || c == 'd';
}

int validateDateFmt(const char *input, const char* fmt)
{
    if (strlen(input) != strlen(fmt)) return LENGTH_ERROR;

    Date date = { 0, 0, 0 };

    for (size_t i = 0; i < strlen(fmt); i++) {
        if (isdigit(input[i]) && isdatefmt(fmt[i])) {
            int digit = input[i] - '0';
            if (fmt[i] == 'y') {
                date.year *= 10;
                date.year += digit;
            } else if (fmt[i] == 'm') {
                date.month *= 10;
                date.month += digit;
            } else if (fmt[i] == 'd') {
                date.day *= 10;
                date.day += digit;
            }
            continue;
        }
        if (input[i] == fmt[i] && fmt[i] == '/') {
            continue;
        }
        return FORMAT_ERROR;
    }
    date.month--;

    if (date.month < JANUARY || date.month > DECEMBER) {
        return MONTH_ERROR;
    }
    
    int maxDay;
    if (date.month == FEBRUARY) {
        maxDay = isLeapYear(date.year)? 29 : 28;
    } else if (date.month % 2 && date.month < JULY) {
        maxDay = 30;
    } else if (date.month % 2 == 0 && date.month > AUGUST) {
        maxDay = 30;
    } else {
        maxDay = 31;
    }
    
    if (date.day < 1 || date.day > maxDay) {
        return DAY_ERROR;
    }

    return DATE_OK;
}
