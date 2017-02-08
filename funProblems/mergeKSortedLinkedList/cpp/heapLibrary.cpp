/*
* FunctionLibrary
* Copyright (C) 2017  Mohit Raj <mohit.raj@st.niituniversity.in>
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

#include <iostream>
#include "heapLibrary.h"

using namespace std;

void maxHeapify (int *arr, int i, int heapSize)
{
    int l = 2 * i, largest, temp;
    int r = 2 * i + 1;

    if (l <= heapSize && arr[l] > arr[i])
        largest = l;
    else
        largest = i;
    if (r <= heapSize && arr[r] > arr[largest])
        largest = r;

    if(largest != i)
    {
        temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        maxHeapify (arr, largest, heapSize);
    }
}

void buildHeap (int *arr, int x)
{
    int heapSize = x;
    int i;
    for (i = heapSize / 2; i > -1; i--)
        maxHeapify (arr, i, heapSize);
}

int extractMax (int *arr, int x)
{
    int heapSize = x + 1;

    if(heapSize < 1)
        cout << "Error found" << endl;

    int max = arr[0];
    arr[0] = arr[x];
    heapSize--;

    maxHeapify (arr, 1, heapSize);

    return max;
}

void heapIncreaseKey (int *arr, int i, int key)
{
    int temp;
    if(key < arr[i])
        cout << "Error found" << endl;

    arr[i] = key;
    while (i > 0 && arr[i / 2] < arr[i])
    {
        temp = arr[i / 2];
        arr[i / 2] = arr[i];
        arr[i] = temp;
        i = i / 2;
    }
}

void insert (int *arr, int key, int x)
{
    int heapSize = x;
    arr[heapSize] = -9999;
    heapIncreaseKey (arr, heapSize, key);
}
