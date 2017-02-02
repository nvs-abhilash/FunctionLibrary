#include <stdio.h>
#include <malloc.h>
#include "DisplayArray.c"
int MergeHalves(int* Arr, int Low, int High)
{
    int Mid = (Low + High)/2;
    int i = Low, j = Mid + 1;
    int k = 0;

    int* Arr2 = malloc(sizeof (int) * (High - Low + 1));

    while ((i <= Mid) && (j <= High))
    {
        if (Arr[i] <= Arr[j])
        {
            Arr2[k++] = Arr[i++];
        }

        else
        {
            Arr2[k++] = Arr[j++];
        }
    }

    while (i <= Mid)
    {
        Arr2[k++] = Arr[i++];
    }

    while (j <= High)
    {
        Arr2[k++] = Arr[j++];
    }

    i = Low;

    while (i <= High)
    {
        Arr[i] = Arr2[i - Low];
        i++;
    }

    free(Arr2);
    return 0;
}

int MergeSort(int* Arr, int Low, int High)
{
    if (Low < High)
    {
        int Mid = (Low + High) / 2;

        MergeSort(Arr, Low, Mid);
        MergeSort(Arr, Mid + 1, High);

        MergeHalves(Arr, Low, High);
    }
}

// Test code to run the function.

/*
int main()
{
    int Arr [] = {9,8,5,7,3,4,2,6,1,0};
    int Size = 10;

    MergeSort(Arr, 0, 9);

    printf ("Sorted array: ");
    DisplayArr(Arr, Size);

    return 0;
}
*/
