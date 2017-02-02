#include <stdio.h>
#include "DisplayArray.c"
#include "Swap.c"

int BubbleSort(int *Arr, int Size)
{
    if (Size < 0)
        return 1;
        
    int i = 0, j = 0;
    for (i = 0; i < Size; i++)
    {
        for (j = 1; j < (Size - i); j++)
        {
            if (Arr[j - 1] > Arr[j])
                Swap (Arr, j - 1, j);
        }
    }

    return 0;
}


// Test code to run the function.

/*
int main()
{
    int Arr [] = {9,8,5,7,3,4,2,6,1,0};
    int Size = 10;

    BubbleSort(Arr, Size);

    printf ("Sorted array: ");
    DisplayArr(Arr, Size);

    return 0;
}
*/
