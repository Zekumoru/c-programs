#include "test.h"
#include "date.h"
#include "utils.h"
#include <stdlib.h>

void test(int y1, int m1, int d1, int y2, int m2, int d2, int expected)
{
    Date *date1 = NULL;
    Date *date2 = NULL;

    date1 = createDate(y1, m1, d1);
    date2 = createDate(y2, m2, d2);

    const int days = countDays(date1, date2);
    println("%d/%d/%d -> %d/%d/%d: %s (Expected: %d; Received: %d)", y1, m1 + 1, d1, y2, m2 + 1, d2, (days == expected)? "PASS" : "FAIL", expected, days);

    free(date1);
    free(date2);
}

void testAll()
{
    test(2023, JANUARY, 1, 2023, DECEMBER, 31, 364);
    test(2023, DECEMBER, 31, 2023, JANUARY, 1, 364);

    test(2023, JANUARY, 1, 2023, JANUARY, 31, 30);
    test(2023, JANUARY, 31, 2023, JANUARY, 1, 30);
    
    test(2023, JANUARY, 1, 2023, FEBRUARY, 28, 58);
    test(2023, FEBRUARY, 28, 2023, JANUARY, 1, 58);
    
    test(2024, JANUARY, 1, 2024, DECEMBER, 31, 365);
    test(2024, DECEMBER, 31, 2024, JANUARY, 1, 365);

    test(2023, FEBRUARY, 28, 2024, FEBRUARY, 28, 365);
    test(2024, FEBRUARY, 28, 2023, FEBRUARY, 28, 365);

    test(2020, FEBRUARY, 28, 2024, FEBRUARY, 28, 1461);
    test(2024, FEBRUARY, 28, 2020, FEBRUARY, 28, 1461);

    test(2020, MARCH, 1, 2024, FEBRUARY, 28, 1459);
    test(2024, FEBRUARY, 28, 2020, MARCH, 1, 1459);

    test(2020, MARCH, 1, 2024, MARCH, 1, 1461);
    test(2024, MARCH, 1, 2020, MARCH, 1, 1461);
}
