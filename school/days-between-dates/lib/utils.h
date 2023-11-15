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
 * \brief Displays an interactive menu with the given title and options.
 *
 * \param title The title of the menu.
 * \param options An array of strings representing menu options.
 * \param optionsSize The number of options in the array.
 * \return The index of the selected option.
 * \note The function returns -1 if the selection is invalid or not provided interactively.
 */
int showInteractiveMenu(const char *title, const char *options[], int optionsSize);

#endif // UTILS_H
