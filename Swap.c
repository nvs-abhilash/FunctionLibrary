#include <stdio.h>

int Swap (int* Arr, int First, int Second)
{
  if (First == Second)
    return 1;

  Arr[First] = Arr[First] - Arr[Second];
  Arr[Second] = Arr[First] + Arr[Second];
  Arr[First] = Arr[Second] - Arr[First];
  return 0;
}
