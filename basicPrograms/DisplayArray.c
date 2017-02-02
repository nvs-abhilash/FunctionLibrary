#include <stdio.h>

int DisplayArr (int* Arr, int Size)
{
  if (Size <= 0)
    return 1;
  int i = 0;
  while (i < Size)
    printf ("%d ", Arr[i++]);
  printf("\n" );

  return 0;
}
