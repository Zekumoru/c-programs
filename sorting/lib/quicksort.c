#include "sort.h"
#include "array.h"
#include <stdlib.h>
#include <time.h>

int partition(int array[], int start, int end);
int r_partition(int array[], int start, int end);
void _quicksort(int array[], int start, int end);

void quicksort(int array[], int arraySize)
{
  _quicksort(array, 0, arraySize - 1);
}

void _quicksort(int array[], int start, int end)
{
  if (end <= start) return;

  int pivot = r_partition(array, start, end);
  _quicksort(array, start, pivot - 1);
  _quicksort(array, pivot + 1, end);
}

int r_partition(int array[], int start, int end)
{
  srand(time(NULL));
  int randomPivotIndex = rand() % (end - start + 1) + start;
  swap(&array[randomPivotIndex], &array[end]);
  return partition(array, start, end);
}

int partition(int array[], int start, int end)
{
  int pivot = array[end]; // set pivot to end of array
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
