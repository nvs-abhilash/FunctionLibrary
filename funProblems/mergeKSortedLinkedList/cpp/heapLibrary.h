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

#ifndef HEAP_LIBRARY_H
#define HEAP_LIBRARY_H

void maxHeapify (int *arr, int i, int heapSize);

void buildHeap (int *arr, int x);

int extractMax (int *arr, int x);

void heapIncreaseKey (int *arr, int i, int key);

void insert (int *arr, int key, int x);

#endif
