#ifndef DATE_H
#define DATE_H

#include <stdbool.h>
#define SEC_PER_DAY 86400

typedef struct Date {
    int year;
    int month;
    int day;
} Date;

enum Month {
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

enum DateValidation {
    DATE_OK,
    LENGTH_ERROR,
    FORMAT_ERROR,
    MONTH_ERROR,
    DAY_ERROR
};

Date *createDate(int year, int month, int day);
int countDays(Date d1, Date d2);

struct tm *dateToTm(Date date);

bool isLeapYear(int year);
int validateDateFmt(const char *input, const char* fmt, Date **out);

#endif // DATE_H
