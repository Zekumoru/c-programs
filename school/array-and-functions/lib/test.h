/**
 * \file tests.h
 * \brief Header file containing functions for array comparison and various array operation tests.
 */

#ifndef ARRAY_TESTS_H
#define ARRAY_TESTS_H

#include <stdbool.h>

/**
 * \brief Compares two double arrays for equality.
 * \param arr1 The first input array for comparison.
 * \param arr2 The second input array for comparison.
 * \param length The length of the arrays to be compared.
 * \return true if the arrays are equal (element-wise), false otherwise.
 */
bool compareArray(double arr1[], double arr2[], int length);

/**
 * \brief Executes various mathematical tests on arrays.
 * Tests include sum, multiplication, and average.
 */
void array_math_tests();

/**
 * \brief Executes tests related to finding indices in arrays.
 */
void array_indexOf_tests();

/**
 * \brief Executes tests related to array reversal.
 */
void array_reverse_tests();

/**
 * \brief Executes tests on the mergesort algorithm.
 */
void mergesort_tests();

/**
 * \brief Executes all the array operation tests available.
 */
void run_all_tests();

#endif // ARRAY_TESTS_H
