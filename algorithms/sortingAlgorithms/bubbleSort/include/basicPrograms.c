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
