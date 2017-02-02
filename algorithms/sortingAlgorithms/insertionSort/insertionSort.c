#include <stdio.h>
#include "DisplayArray.c"

int InsertionSort(int* Arr, int Size)
{
    int i = 0, j = 0, Temp = 0;
    for (i = 1; i < Size; i++)
    {
        j = i - 1;
        Temp = Arr[i];
        while (j >= 0 && Arr[j] > Temp)
        {
            Arr[j + 1] = Arr[j];
            j--;
        }

        Arr[j + 1] = Temp;
    }
}

// Test code to run the function.

/*
int main()
{
    int Arr [] = {9,8,5,7,3,4,2,6,1,0};
    int Size = 10;

    InsertionSort(Arr, Size);

    printf ("Sorted array: ");
    DisplayArr(Arr, Size);

    return 0;
}
*/
