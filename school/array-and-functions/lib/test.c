#include "test.h"
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include "arrayutils.h"

bool compareArray(double arr1[], double arr2[], int length)
{
    for (int i = 0; i < length; i++) {
        if (arr1[i] != arr2[i]) return false;
    }
    return true;
}

void array_math_sum_tests()
{
    printf("[DESCRIBE] Array Math Sum Tests\n");

    double n1[] = { 2 };
    int l1 = sizeof(n1) / sizeof(double);
    printf("Test that ");
    printArray(n1, l1);
    printf(" has sum of 2");
    assert(sumArray(n1, l1) == 2);
    printf(" [PASSED]\n");
    
    double n2[] = { 2, -2, 0 };
    int l2 = sizeof(n2) / sizeof(double);
    printf("Test that ");
    printArray(n2, l2);
    printf(" has sum of 0");
    assert(sumArray(n2, l2) == 0);
    printf(" [PASSED]\n");

    printf("\n");
}

void array_math_multiply_tests()
{
    printf("[DESCRIBE] Array Math Multiply Tests\n");

    double n1[] = { 2 };
    int l1 = sizeof(n1) / sizeof(double);
    printf("Test that a single element array multiplied is itself");
    assert(multiplyArray(n1, l1) == 2);
    printf(" [PASSED]\n");
    
    double n2[] = { 2, -2, 0 };
    int l2 = sizeof(n2) / sizeof(double);
    printf("Test that multiplying by zero is zero");
    assert(multiplyArray(n2, l2) == 0);
    printf(" [PASSED]\n");

    double n3[] = { 1, 2, 3, 4, 5 };
    int l3 = sizeof(n3) / sizeof(double);
    printf("Test that the multiplication of ");
    printArray(n3, l3);
    printf(" is 120");
    assert(multiplyArray(n3, l3) == 120);
    printf(" [PASSED]\n");

    printf("\n");
}

void array_math_average_tests()
{
    printf("[DESCRIBE] Array Math Average Tests\n");

    double n1[] = { 2 };
    int l1 = sizeof(n1) / sizeof(double);
    printf("Test that the average of a single element array is itself");
    assert(averageArray(n1, l1) == 2);
    printf(" [PASSED]\n");
    
    double n2[] = { 2, -2, 0, 1 };
    int l2 = sizeof(n2) / sizeof(double);
    printf("Test that the average of ");
    printArray(n2, l2);
    printf(" is 0.25");
    assert(averageArray(n2, l2) == 0.25);
    printf(" [PASSED]\n");

    printf("\n");
}

void array_math_tests()
{
    array_math_sum_tests();
    array_math_multiply_tests();
    array_math_average_tests();
}

void array_indexOf_tests()
{
    printf("[DESCRIBE] Array IndexOf Tests\n");

    double n1[] = { 2, 3, 4 };
    int l1 = sizeof(n1) / sizeof(double);
    printf("It should return the correct index");
    assert(indexOf(4, n1, l1) == 2);
    printf(" [PASSED]\n");
    
    double n2[] = { 2, 3, 4 };
    int l2 = sizeof(n2) / sizeof(double);
    printf("It should return an index of -1 if the item is not found");
    assert(indexOf(5, n2, l2) == -1);
    printf(" [PASSED]\n");

    printf("\n");
}

void array_reverse_tests()
{
    printf("[DESCRIBE] Reverse Array Tests\n");

    double n1[] = { 2 };
    double e1[] = { 2 };
    int l1 = sizeof(n1) / sizeof(double);
    printf("Test that the reverse of a single element is itself");
    reverseArray(n1, l1);
    assert(compareArray(n1, e1, l1));
    printf(" [PASSED]\n");
    
    double n2[] = { 2, 3, 4 };
    double e2[] = { 4, 3, 2 };
    int l2 = sizeof(n2) / sizeof(double);
    printf("Test that the reverse of ");
    printArray(n2, l2);
    printf(" is ");
    printArray(e2, l2);
    reverseArray(n2, l2);
    assert(compareArray(n2, e2, l2));
    printf(" [PASSED]\n");

    printf("\n");
}

void mergesort_tests()
{
    printf("[DESCRIBE] Mergesort Tests\n");

    double n1[] = { 2 };
    double e1[] = { 2 };
    int l1 = sizeof(n1) / sizeof(double);
    printf("Test that the sort of a single element is itself");
    mergesort(n1, l1);
    assert(compareArray(n1, e1, l1));
    printf(" [PASSED]\n");
    
    double n2[] = { 4, 3, 2 };
    double e2[] = { 2, 3, 4 };
    int l2 = sizeof(n2) / sizeof(double);
    printf("Test that the sort of ");
    printArray(n2, l2);
    printf(" is ");
    printArray(e2, l2);
    mergesort(n2, l2);
    assert(compareArray(n2, e2, l2));
    printf(" [PASSED]\n");

    double n3[] = { 5, 4, 3, 4, 2, 4, -1, 4 };
    double e3[] = { -1, 2, 3, 4, 4, 4, 4, 5 };
    int l3 = sizeof(n3) / sizeof(double);
    printf("Test that sorting works with duplicate elements");
    mergesort(n3, l3);
    assert(compareArray(n3, e3, l3));
    printf(" [PASSED]\n");
    
    double n4[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    double e4[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int l4 = sizeof(n4) / sizeof(double);
    printf("Test that sorting works with sorted elements");
    mergesort(n4, l4);
    assert(compareArray(n4, e4, l4));
    printf(" [PASSED]\n");

    double n5[] = { 8, 7, 6, 5, 4, 3, 2 ,1 };
    double e5[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int l5 = sizeof(n5) / sizeof(double);
    printf("Test that sorting works with descending elements");
    mergesort(n5, l5);
    assert(compareArray(n5, e5, l5));
    printf(" [PASSED]\n");

    printf("\n");
}


void run_all_tests()
{
    array_math_tests();
    array_indexOf_tests();
    array_reverse_tests();
    mergesort_tests();
}
