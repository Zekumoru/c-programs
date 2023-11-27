/**
 * \file arrayutils.h
 * \brief Header file containing functions for array manipulation.
 */

#ifndef ARRAYUTILS_H
#define ARRAYUTILS_H

/**
 * \brief Prints the elements of a double array.
 * \param array The input array.
 * \param length The length of the array.
 */
void printArray(double array[], int length);

/**
 * \brief Calculates the sum of elements in a double array.
 * \param array The input array.
 * \param length The length of the array.
 * \return The sum of elements in the array.
 */
double sumArray(double array[], int length);

/**
 * \brief Calculates the product of elements in a double array.
 * \param array The input array.
 * \param length The length of the array.
 * \return The product of elements in the array.
 */
double multiplyArray(double array[], int length);

/**
 * \brief Calculates the average of elements in a double array.
 * \param array The input array.
 * \param length The length of the array.
 * \return The average of elements in the array.
 */
double averageArray(double array[], int length);

/**
 * \brief Finds the index of a given item in an array with tolerance.
 * \param item The item to find in the array.
 * \param array The input array.
 * \param length The length of the array.
 * \param tolerance The tolerance value for approximate matches.
 * \return The index of the item in the array; -1 if not found within tolerance.
 */
int indexOfWithTolerance(double item, double array[], int length, double tolerance);

/**
 * \brief Finds the index of a given item in an array.
 * \param item The item to find in the array.
 * \param array The input array.
 * \param length The length of the array.
 * \return The index of the item in the array; -1 if not found.
 */
int indexOf(double item, double array[], int length);

/**
 * \brief Reverses the elements of a double array.
 * \param array The input array.
 * \param length The length of the array.
 */
void reverseArray(double array[], int length);

/**
 * \brief Finds the index of the maximum value in a double array.
 * \param array The input array.
 * \param length The length of the array.
 * \param outMax A pointer to store the maximum value found.
 * \return The index of the maximum value in the array.
 */
int findMaxIndex(double array[], int length, double *outMax);

/**
 * \brief Finds the maximum value in a double array.
 * \param array The input array.
 * \param length The length of the array.
 * \return The maximum value in the array.
 */
double findMax(double array[], int length);

/**
 * \brief Finds the index of the minimum value in a double array.
 * \param array The input array.
 * \param length The length of the array.
 * \param outMin A pointer to store the minimum value found.
 * \return The index of the minimum value in the array.
 */
int findMinIndex(double array[], int length, double *outMin);

/**
 * \brief Finds the minimum value in a double array.
 * \param array The input array.
 * \param length The length of the array.
 * \return The minimum value in the array.
 */
double findMin(double array[], int length);

/**
 * \brief Sorts a double array in ascending order using the merge sort algorithm.
 * \param array The input array to be sorted.
 * \param length The length of the array.
 */
void mergesort(double array[], int length);

#endif // ARRAYUTILS_H
