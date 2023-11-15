#ifndef DATE_H
#define DATE_H

#include <stdbool.h>
#define SEC_PER_DAY 86400

/**
 * \struct Date
 * \brief Represents a date with year, month, and day.
 */
typedef struct Date {
    int year;   /**< Year of the date. */
    int month;  /**< Month of the date. */
    int day;    /**< Day of the date. */
} Date;

/**
 * \enum Month
 * \brief Represents the months of the year.
 */
enum Month {
    JANUARY,    /**< January */
    FEBRUARY,   /**< February */
    MARCH,      /**< March */
    APRIL,      /**< April */
    MAY,        /**< May */
    JUNE,       /**< June */
    JULY,       /**< July */
    AUGUST,     /**< August */
    SEPTEMBER,  /**< September */
    OCTOBER,    /**< October */
    NOVEMBER,   /**< November */
    DECEMBER    /**< December */
};

/**
 * \enum DateValidation
 * \brief Represents the status of date validation
 */
enum DateValidation {
    DATE_OK,        /**< Date is valid. */
    LENGTH_ERROR,   /**< Error due to invalid length. */
    FORMAT_ERROR,   /**< Error due to invalid format. */
    MONTH_ERROR,    /**< Error due to invalid month. */
    DAY_ERROR       /**< Error due to invalid day. */
};

/**
 * \brief Creates a Date structure with the specified year, month, and day.
 *
 * \param year The year of the date.
 * \param month The month of the date.
 * \param day The day of the date.
 * \return A pointer to the created Date structure.
 */
Date *createDate(int year, int month, int day);

/**
 * \brief Calculates the number of days from the beginning of the year to the given date.
 *
 * \param date Pointer to the Date structure representing the date.
 * \return The number of days from the start of the year to the given date.
 * \note Assumes a valid Date structure is provided.
 */
int daysSinceStartOfYear(Date *date);

/**
 * \brief Counts the number of days between two Date structures.
 *
 * \param d1 Pointer to the first Date structure.
 * \param d2 Pointer to the second Date structure.
 * \return The number of days between the two dates.
 */
int countDays(Date *d1, Date *d2);

/**
 * \brief Checks if a given year is a leap year.
 *
 * \param year The year to be checked.
 * \return true if the year is a leap year, false otherwise.
 */
bool isLeapYear(int year);

/**
 * \brief Validates a date string against a specified format.
 *
 * \param input The input date string.
 * \param fmt The format string for validation.
 * \param[out] date Pointer to store the validated Date structure.
 * \param[out] maxDay Pointer to store the maximum day of the validated month.
 * \return An integer representing the validation status (DateValidation enum).
 */
int validateDateFmt(const char *input, const char* fmt, Date **date, int *maxDay);

#endif // DATE_H
