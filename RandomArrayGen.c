#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
// For test function use only.
//#include "DisplayArray.c"
#include "Swap.c"

int GenRandArr (int* Arr, int N, int LowerRange, int HigherRange)
{
    srand (time(NULL));

    int MaxSize = N;
    int i = 0, r = 0;

    for (i = 0; i < MaxSize; i++)
    {
        Arr[i] = LowerRange + (rand() % (HigherRange - LowerRange));
    }

    while (MaxSize > 0)
    {
        r = rand() % MaxSize;
        //Swap MaxSize and r
        if (r != MaxSize - 1)
        Swap (Arr, r, MaxSize - 1);
        MaxSize--;
    }

    return 0;
}

// Test code to run the functions.
/*
int main(int argc, char const *argv[])
{
int Size = 10;
int *A = malloc(sizeof(int) * Size);

GenRandArr(A, Size, 0, 1000);

DisplayArr(A, Size);

free (A);
return 0;
}
*/
