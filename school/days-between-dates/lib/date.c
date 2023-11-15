#include "date.h"
#include <time.h>

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
    timeStruct->tm_mon = date.month - 1;
    timeStruct->tm_mday = date.day;

    return timeStruct;
}

int countDays(Date d1, Date d2)
{
    time_t t1 = mktime(dateToTm(d1));
    time_t t2 = mktime(dateToTm(d2));
    return (t1 - t2) / SEC_PER_DAY;
}