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
#include "basicPrograms.h"
#include "bubbleSort.h"

// Test code to run the bubbleSort function.
int main()
{
    int arr[] = {9, 8, 5, 7, 3, 4, 2, 6, 1, 0};
    int arrSize = 10;

    bubbleSort(arr, arrSize);

    printf ("Sorted array: ");
    displayArr(arr, arrSize);

    return 0;
}
