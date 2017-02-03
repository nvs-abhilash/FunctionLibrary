#include <stdio.h>
#include "basicPrograms.h"
#include "bubbleSort.h"

// Test code to run the bubbleSort function.
int main()
{
    int arr[] = {9, 8, 5, 7, 3, 4, 2, 6, 1, 0};
    int arrSize = 10;

    bubbleSort(arr, arrSize);

    printf ("Sorted array: ");
    displayArr(arr, arrSize);

    return 0;
}
