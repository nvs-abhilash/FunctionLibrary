#include <stdio.h>
#include "basicPrograms.h"

int bubbleSort (int *arr, int arrSize)
{
    if (arr == NULL || arrSize < 0)
        return 1;

    int flag, i;

    do
    {
      flag = 0;

      for (i = 0; i < arrSize - 1; ++i)
      {
        if (arr[i] > arr[i + 1])
        {
          flag = 1;
          swap (arr, i, i + 1);
        }
      }
    } while (flag);

    return 0;
}
