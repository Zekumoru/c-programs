#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <stddef.h>

/**
 * \file randomizer.h
 * \brief Header file containing declarations for randomizer functions.
 */

extern const char CHAR_START;   ///< The start of the character range which is the space ' ' character.
extern const char CHAR_END;     ///< The end of the character range which is the tilde '~' character.
extern const size_t CHAR_TOTAL; ///< Total number of characters to generate.

/**
 * \brief Generates a random integer between a given range.
 * 
 * \param min The minimum value of the range (inclusive).
 * \param max The maximum value of the range (exclusive).
 * \return The generated random integer.
 */
int randbetween(int min, int max);

/**
 * \brief Generates a random character within the range between ' ' and '~'.
 * \return The generated random character between ' ' and '~'.
 */
char randomize();

/**
 * \brief Gets the table key associated with the character.
 * 
 * \param ch The character to calculate the table key.
 * \return The table key associated with the character.
 */
int getTableKey(char ch);

/**
 * \brief Generates a count table for characters.
 * 
 * Generates a count table containing on how many occurrences each
 * character has during generation.
 * 
 * \param generateN The number of characters to generate.
 * \return A pointer to the generated count table.
 */
int *generateCountTable(size_t generateN);

#endif // RANDOMIZER_H
