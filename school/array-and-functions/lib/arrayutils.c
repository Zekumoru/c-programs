#include "arrayutils.h"
#include <stdio.h>
#include <float.h>

void printArray(double array[], int length)
{
    printf("[");
    for (int i = 0; i < length; i++) {
        printf("%.2lf", array[i]);
        if (i != length - 1) printf(", ");
    }
    printf("]");
}

double sumArray(double array[], int length)
{
    double sum = 0;
    for (int i = 0; i < length; i++) {
        sum += array[i];
    }
    return sum;
}

double multiplyArray(double array[], int length)
{
    double multiplySum = 1;
    for (int i = 0; i < length; i++) {
        multiplySum *= array[i];
    }
    return multiplySum;
}

double averageArray(double array[], int length)
{
    return sumArray(array, length) / (double) length;
}

int indexOfWithTolerance(double item, double array[], int length, double tolerance)
{
    double lowerBound = item - tolerance;
    double upperBound = item + tolerance;
    for (int i = 0; i < length; i++) {
        if (lowerBound <= array[i] && array[i] <= upperBound) {
            return i;
        }
    }
    return -1;
}

int indexOf(double item, double array[], int length)
{
    return indexOfWithTolerance(item, array, length, 1.0E-9);
}

void reverseArray(double array[], int length)
{
    for (int leftPointer = 0, rightPointer = length - 1; leftPointer < rightPointer; leftPointer++, rightPointer--) {
        int temp = array[leftPointer];
        array[leftPointer] = array[rightPointer];
        array[rightPointer] = temp;
    }
}

int findMaxIndex(double array[], int length, double *outMax)
{
    int index = -1;
    if (length >= 1) *outMax = array[0];
    for (int i = 1; i < length; i++) {
        if (array[i] > *outMax) {
            *outMax = array[i];
        }
    }
    return index;
}

double findMax(double array[], int length)
{
    double max = DBL_MIN;
    findMaxIndex(array, length, &max);
    return max;
}

int findMinIndex(double array[], int length, double *outMin)
{
    int index = -1;
    if (length >= 1) *outMin = array[0];
    for (int i = 1; i < length; i++) {
        if (array[i] < *outMin) {
            *outMin = array[i];
        }
    }
    return index;
}

double findMin(double array[], int length)
{
    double min = DBL_MAX;
    findMinIndex(array, length, &min);
    return min;
}