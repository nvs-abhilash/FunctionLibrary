#include <stdio.h>
#include "DisplayArray.c"
#include "BuildHeap.c"

int HeapSort(int* Arr, int Size)
{
    if (Size <= 0)
        return 1;
    if (Size == 1)
        return 0;

    MaxBuildHeap(Arr, Size);

    while (Size --)
    {
        Swap(Arr, 0, Size);
        MaxHeapify(Arr, 0, Size);
    }

    return 0;
}


// Test code to run the function.
/*
int main()
{
    int Arr [] = {9,8,5,7,3,4,2,6,1,0};
    int Size = 10;

    HeapSort(Arr, Size);

    printf ("Sorted array: ");
    DisplayArr(Arr, Size);

    return 0;
}
*/
