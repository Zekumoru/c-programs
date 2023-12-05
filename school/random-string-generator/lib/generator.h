/**
 * \file generator.h
 * \brief Header file containing function declarations for string generation.
 */

#ifndef GENERATOR_H
#define GENERATOR_H

/**
 * \brief Option code for including lowercase alphabetic characters in generated strings.
 */
extern const int LOWERCASE_ALPHA_CHARS;

/**
 * \brief Option code for including uppercase alphabetic characters in generated strings.
 */
extern const int UPPERCASE_ALPHA_CHARS;

/**
 * \brief Option code for including digit characters in generated strings.
 */
extern const int DIGIT_CHARS;

/**
 * \brief Option code for including special characters in generated strings.
 */
extern const int SPECIAL_CHARS;

/**
 * \brief Option code for including all alphabetic characters (both lowercase and uppercase) in generated strings.
 */
extern const int ALPHA_CHARS;

/**
 * \brief Option code for including alphanumeric characters in generated strings.
 */
extern const int ALNUM_CHARS;

/**
 * \brief Option code for including all printable characters in generated strings.
 */
extern const int ALL_PRINTABLE_CHARS;

/**
 * \brief Standardizes the ignore characters array.
 *
 * This function standardizes the ignore characters array to ensure uniqueness and proper formatting.
 *
 * \param ignoreChars The input array of characters to be standardized.
 * \return A dynamically allocated string containing the standardized ignore characters.
 * \warning The caller is responsible for freeing the allocated memory.
 */
char *standardizeIgnoreChars(const char ignoreChars[]);

/**
 * \brief Generates a string based on specified parameters.
 *
 * Random string generator with time complexity of:
 *      O(n log n) + O(k)
 * where:
 *  - n is the length of the parameter 'ignoreChars'
 *  - k is the length of the string to generate
 * 
 * If the length of the string to generate and the length
 * of the 'ignoreChars' are the same then the time 
 * complexity is of O(n log n)
 * 
 * \param length The length of the generated string.
 * \param charTypes The types of characters to include in the generated string.
 * \param ignoreChars An array of characters to exclude from the generated string.
 * \return A dynamically allocated string containing the generated characters.
 * \warning The caller is responsible for freeing the allocated memory.
 */
char *generateString(const int length, const int charTypes, const char ignoreChars[]);

#endif // GENERATOR_H
