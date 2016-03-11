#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>
#include "RandomArrayGen.c"
#include "HeapSort.c"

int CustomSwap (int* Arr[2], int First, int Second);
int CustomMinHeapify(int* Arr[2], int Root, int Size);
int CustomMinBuildHeap(int* Arr[2], int Size);


int main()
{
    int N = 1000;
    int K = 10;
    int i = 0, j = 0;
    int K2 = K;
    int **Arr = malloc (sizeof(int *) * K);
    int R = 0;
    int l = 0;
    int LowIndex = 0;
    srand (time(NULL));
    printf ("\n\tGenrating 10 random arrays, it takes time to make it random ;) please wait...");
    for (i = 0; i < K; i++)
    {
        printf ("\n\tGenerating array %d...", i + 1);
        Arr[i] = malloc (sizeof(int) * N);
        //int GenRandArr (int* Arr, int N, int LowerRange, int HigherRange)
        R = rand() % 500;
        GenRandArr(Arr[i], N, R, R + N);
        printf("\n\tSorting array %d...", i + 1);
        HeapSort(Arr[i], N);
        // For loop to pause for increasing randomness.
        for (l = 0; l < 1000000000; l++);

        printf ("\t... done!\n");
    }

    int* MinHeapArray[2];
    MinHeapArray[0] = malloc (sizeof(int) * K);
    MinHeapArray[1] = malloc (sizeof(int) * K);

    int* Index = malloc (sizeof(int) * K);

    for (i = 0; i < K; i++)
    {
            MinHeapArray[0][i] = Arr[i][0];
            MinHeapArray[1][i] = i;
            Index[i] = 0;
    }


    CustomMinBuildHeap(MinHeapArray, K);

    while (K > 0)
    {
        printf ("%d ", MinHeapArray[0][0]);
        LowIndex = MinHeapArray[1][0];

        if (Index[LowIndex] < N - 1)
        {
            MinHeapArray[0][0] = Arr [LowIndex] [++Index[LowIndex]];
        }

        else if (Index[LowIndex] == N - 1)
        {
            CustomSwap(MinHeapArray, 0, K--);
        }

        CustomMinHeapify(MinHeapArray, 0, K);

    }

    free (MinHeapArray[0]);
    free (MinHeapArray[1]);
    for (i = 0; i < K2; i++)
    {
        free (Arr[i]);
    }
    return 0;

}

int CustomSwap (int* Arr[2], int First, int Second)
{
  if (First == Second)
    return 1;

  Arr[0][First] = Arr[0][First] - Arr[0][Second];
  Arr[0][Second] = Arr[0][First] + Arr[0][Second];
  Arr[0][First] = Arr[0][Second] - Arr[0][First];

  Arr[1][First] = Arr[1][First] - Arr[1][Second];
  Arr[1][Second] = Arr[1][First] + Arr[1][Second];
  Arr[1][First] = Arr[1][Second] - Arr[1][First];

  return 0;
}

int CustomMinHeapify(int* Arr[2], int Root, int Size)
{
    int Smallest = Root;
    int Left = LeftChild(Root);
    int Right = RightChild(Root);

    if ((Left < Size) && (Arr[0][Left] < Arr[0][Smallest]))
        Smallest = Left;

    if ((Right < Size) && (Arr[0][Right] < Arr[0][Smallest]))
        Smallest = Right;

    if (Smallest != Root)
    {
        CustomSwap(Arr, Smallest, Root);
        CustomMinHeapify (Arr, Smallest, Size);
    }

}

int CustomMinBuildHeap(int* Arr[2], int Size)
{
    int i = Root(Size);
    while (i >= 0)
    {
        CustomMinHeapify(Arr, i, Size);
        i--;
    }

    return 0;
}
