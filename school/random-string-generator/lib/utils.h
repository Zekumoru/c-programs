/**
 * \file utils.h
 * \brief Header file containing functions for I/O operations.
 */

#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stdarg.h>

/**
 * \enum MenuItemType
 * \brief Represents the menu item type.
 */
typedef enum MenuItemType {
    BUTTON_MENU_ITEM_TYPE,   /**< Represents a button menu item type. */
    TOGGLE_MENU_ITEM_TYPE    /**< Represents a toggle menu item type. */
} MenuItemType;

/**
 * \struct MenuItem
 * \brief Represents a menu item which can be of type Button or Toggle.
 */
typedef struct MenuItem {
    char *name;             /**< Pointer to the name of the menu item. */
    bool toggled;           /**< Represents whether the menu item is toggled (for toggle type). */
    MenuItemType type;      /**< Type of the menu item: Button or Toggle. */
} MenuItem;

/**
 * \struct Menu
 * \brief Holds the necessary data for the menu to show.
 */
typedef struct Menu {
    char *title;            /**< Pointer to the title of the menu. */
    MenuItem **items;       /**< Pointer to the array of menu items. */
    int itemsSize;          /**< Size of the menu items array. */
    int prevChoice;         /**< Index representing the previous choice in the menu. */
} Menu;

/**
 * \brief Prints a formatted string to the standard output followed by a newline.
 *
 * This function prints a formatted string to the standard output followed by a newline character.
 *
 * \param fmt The format string, similar to printf.
 * \param ... Additional arguments to be formatted.
 */
void println(const char *fmt, ...);

/**
 * \brief Prints a formatted string to the standard output using ncurses and adds a newline.
 *
 * This function prints a formatted string to the standard output using ncurses and adds a newline character.
 *
 * \param fmt The format string, similar to printw.
 * \param ... Additional arguments to be formatted.
 */
void printwln(const char *fmt, ...);

/**
 * \brief Reads a line from the standard input and returns it as a dynamically allocated string.
 *
 * This function reads a line from the standard input and returns it as a dynamically allocated string.
 * The caller is responsible for freeing the allocated memory.
 *
 * \return A pointer to the dynamically allocated string containing the input line.
 */
char *getln();

/**
 * \brief Converts a string to a double value.
 *
 * This function converts a string to a double value according to specified formatting rules.
 *
 * \param string The input string to be converted to a double.
 * \param ... Optional arguments that specify formatting rules.
 *            If the first optional argument is true then also parse comma as a decimal separator.
 * \return The double value parsed from the input string.
 */
double toDouble(const char* string, ...);

/**
 * \brief Retrieves a double value from user input.
 *
 * This function retrieves a double value from user input.
 *
 * \return The double value entered by the user.
 */
double getDouble();

/**
 * \brief Retrieves a double value from user input, allowing comma as a decimal separator.
 *
 * This function retrieves a double value from user input, considering comma as a decimal separator.
 *
 * \note This function supports comma (',') as a decimal separator for input.
 * \return The double value entered by the user, considering comma as a decimal separator.
 */
double getDoubleComma();

/**
 * \brief Creates a dynamically allocated string copy of the input string.
 *
 * This function creates a dynamically allocated string copy of the input string.
 *
 * \param string The input string to be copied.
 * \return A pointer to the dynamically allocated string copy.
 */
char *createString(const char *string);

/**
 * \brief Creates a dynamically allocated formatted string.
 *
 * This function creates a dynamically allocated formatted string.
 *
 * \param fmt The format string, similar to printf.
 * \param ... Additional arguments to be formatted.
 * \return A pointer to the dynamically allocated formatted string.
 */
char *createFormattedString(const char *fmt, ...);

/**
 * \brief Creates a dynamically allocated formatted string using a va_list.
 *
 * This function creates a dynamically allocated formatted string using a va_list.
 *
 * \param fmt The format string, similar to printf.
 * \param params A va_list containing additional arguments to be formatted.
 * \return A pointer to the dynamically allocated formatted string.
 */
char *v_createFormattedString(const char *fmt, va_list params);

/**
 * \brief Creates a menu item with the specified name and type.
 *
 * This function creates a menu item with the specified name and type.
 *
 * \param name The name of the menu item.
 * \param type The type of the menu item (Button or Toggle).
 * \param ... Additional arguments for the 'name' to be formatted.
 * \return A pointer to the created menu item.
 */
MenuItem *createMenuItem(const char *name, MenuItemType type, ...);

/**
 * \brief Destroys a menu item, freeing allocated memory.
 *
 * This function destroys a menu item, freeing the allocated memory.
 *
 * \param item The menu item to be destroyed.
 */
void destroyMenuItem(MenuItem *item);

/**
 * \brief Displays a menu and retrieves the user's choice.
 *
 * This function displays a menu and retrieves the user's choice.
 *
 * \param menu Pointer to the menu structure to be displayed.
 * \return The index of the chosen menu item.
 */
int showMenu(Menu *menu);

/**
 * \brief Destroys a menu, freeing allocated memory.
 *
 * This function destroys a menu, freeing the allocated memory.
 *
 * \param menu Pointer to the menu to be destroyed.
 */
void destroyMenu(Menu *menu);

#endif // UTILS_H
