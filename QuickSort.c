#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Swap.c"
#include "DisplayArray.c"

int QuickSort(int* Arr, int Start, int End)
{

    if (Start < End)
    {
        // Taking pivot as a random element.
        srand(time(NULL));

        int PIndex = Start + rand() % (End - Start + 1);
        int Pivot = Arr[PIndex];
        int FirstVal = Start;
        int LastVal = End;

        Swap (Arr, Start, PIndex);
        PIndex = Start;


        while (Start <= End)
        {
            if (Arr[Start] == Pivot)
            {
                Start++;
            }

            else if (Arr[Start] < Pivot)
            {
                Swap(Arr, Start, PIndex);
                Start++;
                PIndex++;
            }

            else
            {
                Swap(Arr, Start, End);
                End--;
            }
        }

        QuickSort (Arr, FirstVal, PIndex - 1);

        QuickSort (Arr, Start, LastVal);
    }

    return 0;
}


// Test code to run the function.

/*
int main()
{
    int Arr [] = {9,8,5,7,3,4,2,6,1,0};
    int Size = 10;

    QuickSort(Arr, 0, 9);

    printf ("Sorted array: ");
    DisplayArr(Arr, Size);

    return 0;
}
*/
