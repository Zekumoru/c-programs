/**
 * \file utils.h
 * \brief Header file containing functions for I/O operations.
 */

#ifndef UTILS_H
#define UTILS_H

/**
 * \brief Prints a formatted string to the standard output followed by a newline.
 *
 * \param fmt The format string, similar to printf.
 * \param ... Additional arguments to be formatted.
 */
void println(const char *fmt, ...);

/**
 * \brief Prints a formatted string to the standard output using ncurses and adds a newline.
 *
 * \param fmt The format string, similar to printw.
 * \param ... Additional arguments to be formatted.
 */
void printwln(const char *fmt, ...);

/**
 * \brief Reads a line from the standard input and returns it as a dynamically allocated string.
 *
 * \return A pointer to the dynamically allocated string containing the input line.
 * \warning The caller is responsible for freeing the allocated memory.
 */
char *getln();

/**
 * \brief Converts a string to a double value.
 * \param string The input string to be converted to a double.
 * \param ... Optional arguments that specify formatting rules.
 *            If the first optional argument is true then also parse comma as a decimal separator.
 * \return The double value parsed from the input string.
 */
double toDouble(const char* string, ...);

/**
 * \brief Retrieves a double value from user input.
 * \return The double value entered by the user.
 */
double getDouble();

/**
 * \brief Retrieves a double value from user input, allowing comma as a decimal separator.
 * \note This function supports comma (',') as a decimal separator for input.
 * \return The double value entered by the user, considering comma as a decimal separator.
 */
double getDoubleComma();

/**
 * \brief Displays an interactive menu with the given title and options.
 *
 * \param title The title of the menu.
 * \param options An array of strings representing menu options.
 * \param optionsSize The number of options in the array.
 * \param previousChoice The previous selected option.
 * \return The index of the selected option.
 * \note The function returns -1 if the selection is invalid or not provided interactively.
 */
int showInteractiveMenu(const char *title, const char *options[], int optionsSize, int previousChoice);

#endif // UTILS_H
