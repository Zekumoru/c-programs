#include "sort.h"
#include <stdlib.h>

// internal mergesort function helper
void mergesort_int(int array[], int start, int end);
void merge(int array[], int start, int middle, int end);

void mergesort(int array[], int size)
{
  mergesort_int(array, 0, size - 1);
}

void mergesort_int(int array[], int start, int end)
{
  if (start >= end) return;

  int middle = (start + end) / 2;
  mergesort_int(array, start, middle);
  mergesort_int(array, middle + 1, end);
  merge(array, start, middle, end);
}

void merge(int array[], int start, int middle, int end)
{
  int i = start;
  int j = middle + 1;
  int k;
  int *temp = malloc((end - start + 1) * sizeof(array[0]));

  for (k = 0; i <= middle && j <= end; k++) {
    if (array[i] < array[j]) {
      temp[k] = array[i];
      i++;
    } else {
      temp[k] = array[j];
      j++;
    }
  }

  for (; i <= middle; i++, k++) temp[k] = array[i];
  for (; j <= end; j++, k++) temp[k] = array[j];

  for (i = start, k = 0; i <= end; i++, k++) array[i] = temp[k];
}
