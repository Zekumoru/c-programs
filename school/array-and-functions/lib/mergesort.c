#include "arrayutils.h"
#include <stdlib.h>

void mergesort_merge(double array[], int lowerIndex, int middleIndex, int upperIndex)
{
    int tempSize = upperIndex - lowerIndex + 1;
    double *temp = malloc(tempSize * sizeof(double));
    int leftPointer = lowerIndex;
    int rightPointer = middleIndex + 1;
    int index = 0;

    // Sort array by comparing lower half against its upper half
    // and putting them sorted in the temp array
    for (; leftPointer <= middleIndex && rightPointer <= upperIndex; index++) {
        if (array[leftPointer] > array[rightPointer]) {
            temp[index] = array[rightPointer];
            rightPointer++;
        } else {
            temp[index] = array[leftPointer];
            leftPointer++;
        }
    }

    // Copy over remaining lower half to temp sorted array
    for (; leftPointer <= middleIndex; leftPointer++, index++) {
        temp[index] = array[leftPointer];
    }

    // Copy over remaining higher half to temp sorted array
    for (; rightPointer <= upperIndex; rightPointer++, index++) {
        temp[index] = array[rightPointer];
    }

    // Copy sorted temp array to the actual array
    for (int i = 0; i < tempSize; i++) {
        array[lowerIndex + i] = temp[i];
    }

    free(temp);
}

void mergesort_split(double array[], int lowerIndex, int upperIndex)
{
    if (lowerIndex == upperIndex) return;

    int middleIndex = (lowerIndex + upperIndex) / 2;

    // Split array to lower half and upper half
    mergesort_split(array, lowerIndex, middleIndex);
    mergesort_split(array, middleIndex + 1, upperIndex);

    mergesort_merge(array, lowerIndex, middleIndex, upperIndex);
}

void mergesort(double array[], int length)
{
    mergesort_split(array, 0, length - 1);
}
