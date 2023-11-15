#ifndef DATE_H
#define DATE_H

#include <stdbool.h>
#define SEC_PER_DAY 86400

typedef struct Date {
    int year;
    int month;
    int day;
} Date;

Date createDate(int year, int month, int day);
int countDays(Date d1, Date d2);

struct tm *dateToTm(Date date);

bool isLeapYear(int year);

#endif // DATE_H
