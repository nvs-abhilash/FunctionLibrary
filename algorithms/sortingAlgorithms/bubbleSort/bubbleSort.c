/*
* FunctionLibrary
* Copyright (C) 2017  NVS Abhilash <nvs232@gmail.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>
*
*/

#include <stdio.h>
#include "include/basicPrograms.h"

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
