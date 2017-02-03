#include <stdio.h>

int displayArr (int* arr, int arrSize)
{
  if (arrSize <= 0)
    return 1;

  int i = 0;
  while (i < arrSize)
    printf ("%d ", arr[i++]);
  printf ("\n");

  return 0;
}

void swap (int *arr, int index1, int index2)
{
  int temp = arr[index1];
  arr[index1] = arr[index2];
  arr[index2] = temp;
}
