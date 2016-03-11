#include <stdio.h>
#include "DisplayArray.c"
#include "Swap.c"

int SelectionSort (int* Arr, int Size)
{
    if (Size <= 0)
        return 1;

    int i = 0, j = 0, Min = 0;
    for (i = 0; i < Size - 1; i++)
    {
        Min = i;

        for (j = i + 1; j < Size; j++)
        {
            // Find the smallest number.
            if (Arr[j] < Arr[Min])
                Min = j;
        }

        // Swap Min and i
        if (i != Min)
            Swap (Arr, Min, i);
    }

    return 0;
}

// Test code to run the function.

/*
int main()
{
    int Arr [] = {9,8,5,7,3,4,2,6,1,0};
    int Size = 10;

    SelectionSort(Arr, Size);

    printf ("Sorted array: ");
    DisplayArr(Arr, Size);

    return 0;
}
*/
