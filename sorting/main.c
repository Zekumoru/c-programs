#include <stdio.h>
#include "lib/array.h"
#include "lib/sort.h"

int main()
{
  int array[] = { 8, 2, 5, 3, 9, 4, 7, 6, 1 };
  int arraySize = sizeof(array) / sizeof(array[0]);

  printArray(array, arraySize);
  printf("\n");

  quicksort(array, arraySize);

  printArray(array, arraySize);
  printf("\n");

  return 0;
}
