#ifndef UI_H
#define UI_H

#include <ncurses.h>
#include <stdbool.h>

/**
 * \brief Print formatted string followed by a newline in the specified window.
 *
 * \param window The window where the text will be printed.
 * \param fmt The format string (follows printf-style formatting).
 * \param ... Additional arguments for formatting the string.
 */
void wprintwln(WINDOW *window, const char *fmt, ...);

/**
 * \brief Check if the given key corresponds to the Enter key.
 *
 * \param key The key code to check.
 * \return true if the key is the Enter key, false otherwise.
 */
bool isEnterKey(int key);

/**
 * \brief Create a new interactive window using ncurses.
 * 
 * Creates a new interactive window with the cursor hidden,
 * keypad active (which allows for arrow keys input), and
 * disables character pressed on the screen.
 *
 * \return A pointer to the created window.
 */
WINDOW *createInteractiveWindow();

/**
 * \brief Destroy the specified window.
 *
 * \param window The window to be destroyed.
 */
void destroyWindow(WINDOW *window);

/**
 * \brief Display a menu window with the specified title and options.
 *
 * \param title The title of the menu window.
 * \param options An array of strings representing the menu options.
 * \param optionsSize The size of the options array.
 * \return The index of the selected option.
 */
int showMenuWindow(const char *title, const char *options[], int optionsSize);

/**
 * \brief Display a window to generate a specified number of characters.
 * 
 * Displays a window which asks how many characters to generate and then
 * puts the characters' occurrences in a count table which is then returned.
 *
 * \param[out] num A pointer to the specified number of characters to generate.
 * \return A pointer to the generated count table.
 */
int *showGenerateWindow(int *num);

/**
 * \brief Display a window showing the lookup results based on the count table.
 *
 * \param countTable The table containing counts of the characters' occurrences.
 * \param generatedN The specified number of characters to generate.
 */
void showLookupWindow(int* countTable, int generatedN);

/**
 * \brief Output a list of characters' counts based on the count table.
 *
 * \param countTable The table containing counts of the characters' occurrences.
 * \param generatedN The specified number of characters to generate.
 */
void showListCounts(int* countTable, int generatedN);

#endif // UI_H
