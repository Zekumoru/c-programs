#include "sort.h"
#include "array.h"
#include <stdlib.h>

// using Lomuto's partitioning algorithm
// partition means dividing the array into
// two parts putting the lowest elements
// than the pivot on the left and the highest
// elements on the right of the pivot
int partition(int array[], int start, int end);

// use a random pivot for best average case
// pivot means it's the central point between
// two partitions
int r_partition(int array[], int start, int end);

// internal quicksort function
void _quicksort(int array[], int start, int end);

// start of quicksort
void quicksort(int array[], int arraySize)
{
  _quicksort(array, 0, arraySize - 1);
}

void _quicksort(int array[], int start, int end)
{
  // base case
  if (end <= start) return;

  // get the pivot that is already in its
  // actual position in the sorted array
  int pivot = r_partition(array, start, end);

  // recursively quicksort left and right partitions from pivot
  _quicksort(array, start, pivot - 1);
  _quicksort(array, pivot + 1, end);
}

int r_partition(int array[], int start, int end)
{
  // get random pivot index
  int randomPivotIndex = rand() % (end - start + 1) + start;
  // then swap it with the last element, this is required
  // for Lomuto's algorithm
  swap(&array[randomPivotIndex], &array[end]);

  // start partitioning/sorting
  return partition(array, start, end);
}

int partition(int array[], int start, int end)
{
  // set pivot to end of array
  // remember that Lomuto's algorithm takes
  // the last element as the pivot
  int pivot = array[end];
  int i = start - 1;

  for (int j = start; j <= end - 1; j++) {
    if (array[j] < pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  i++;
  swap(&array[i], &array[end]);

  return i;
}
