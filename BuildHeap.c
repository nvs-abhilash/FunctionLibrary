#include <stdio.h>
// Include for testing purpose
// #include "DisplayArray.c"
//#include "Swap.c"

int Root(int Child)
{
    return (Child - 1) / 2;
}

int LeftChild(int Parent)
{
    return Parent * 2 + 1;
}

int RightChild(int Parent)
{
    return Parent * 2 + 2;
}

int MinHeapify(int* Arr, int Root, int Size)
{
    int Smallest = Root;
    int Left = LeftChild(Root);
    int Right = RightChild(Root);

    if ((Left < Size) && (Arr[Left] < Arr[Smallest]))
        Smallest = Left;

    if ((Right < Size) && (Arr[Right] < Arr[Smallest]))
        Smallest = Right;

    if (Smallest != Root)
    {
        Swap(Arr, Smallest, Root);
        MinHeapify (Arr, Smallest, Size);
    }

}

int MinBuildHeap(int* Arr, int Size)
{
    int i = Root(Size);
    while (i >= 0)
    {
        MinHeapify(Arr, i, Size);
        i--;
    }

    return 0;
}


int MaxHeapify(int* Arr, int Root, int Size)
{
    int Largest = Root;
    int Left = LeftChild(Root);
    int Right = RightChild(Root);

    if ((Left < Size) && (Arr[Left] > Arr[Largest]))
        Largest = Left;

    if ((Right < Size) && (Arr[Right] > Arr[Largest]))
        Largest = Right;

    if (Largest != Root)
    {
        Swap(Arr, Largest, Root);
        MaxHeapify (Arr, Largest, Size);
    }
}

int MaxBuildHeap(int* Arr, int Size)
{
    int i = Root(Size);

    while (i >= 0)
    {
        MaxHeapify(Arr, i, Size);
        i--;
    }
}

// Test code to run the function.

/*
int main()
{
    int Arr1 [] = {9,8,5,7,3,4,2,6,1,0};
    int Arr2 [] = {9,8,5,7,3,4,2,6,1,0};

    int Size = 10;

    MinBuildHeap(Arr1, 10);
    printf ("\nMin Heap: ");
    DisplayArr(Arr1, Size);


    MaxBuildHeap(Arr2, 10);
    printf ("\nMax Heap: ");
    DisplayArr(Arr2, Size);

    return 0;
}
*/
