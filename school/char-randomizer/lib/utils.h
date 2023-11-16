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
 * \brief Reads a line from the standard input and returns it as a dynamically allocated string.
 *
 * \return A pointer to the dynamically allocated string containing the input line.
 * \warning The caller is responsible for freeing the allocated memory.
 */
char *getln();

#endif // UTILS_H
