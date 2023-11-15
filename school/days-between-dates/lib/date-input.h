#ifndef DATE_INPUT_H
#define DATE_INPUT_H

#include "date.h"

/**
 * @brief Array of const char pointers representing date formats.
 *
 * This array contains string literals representing various date formats:
 * - "dd/mm/yyyy"
 * - "mm/dd/yyyy"
 * - "yyyy/mm/dd"
 */
extern const char *dateFormats[];

/**
 * \brief Prompts the user for date input and returns a Date structure.
 *
 * \param prompt The prompt message displayed to the user.
 * \param fmtOption The format option for date input:
 *                  - 0: Day-Month-Year
 *                  - 1: Month-Day-Year
 *                  - 2: Year-Month-Day
 * \return A pointer to the Date structure representing the user-inputted date.
 * \note The caller is responsible for freeing the allocated memory.
 * \warning The function may return NULL if the input is invalid or the memory allocation fails.
 */
Date *getDateInput(const char *prompt, int fmtOption);

#endif // DATE_INPUT_H
