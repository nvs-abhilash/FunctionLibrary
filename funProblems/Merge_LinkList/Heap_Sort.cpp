#include <iostream>
using namespace std;

void Max_Heapify(int *arr,int i, int heap_size)
{
    int l = 2*i, largest, temp;
    int r = 2*i + 1;
    if(l <= heap_size && arr[l] > arr[i])
        largest = l;
    else
        largest = i;
    if(r <= heap_size && arr[r] > arr[largest])
        largest = r;

    if(largest != i)
    {
        temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        Max_Heapify(arr,largest,heap_size);
    }
}

void Build_Heap(int *arr, int x)
{
    int heap_size = x;
    int i;
    for(i = heap_size/2; i > -1; i--)
    {
        Max_Heapify(arr,i,heap_size);
    }
}
int Extract_Max(int *arr,int x)
{
    int heap_size = x+1;
    if(heap_size < 1)
        cout << "Error found\n";
    int max = arr[0];
    arr[0] = arr[x];
    heap_size--;
    Max_Heapify(arr,1,heap_size);
    return max;
}
void Heap_Increase_Key(int *arr,int i,int key)
{
    int temp;
    if(key < arr[i])
        cout << "Error found\n";
    arr[i] = key;
    while(i > 0 && arr[i/2] < arr[i])
    {
        temp = arr[i/2];
        arr[i/2] = arr[i];
        arr[i] = temp;
        i = i/2;
    }
}
void Insert(int *arr,int key,int x)
{
    int heap_size = x;
    arr[heap_size] = -9999;
    Heap_Increase_Key(arr,heap_size,key);
}
void Heap_Sort(int *arr,int heap_size)
{
    int temp;
    heap_size = heap_size - 1;
    int i;
    Build_Heap(arr,heap_size);
    for(i = heap_size; i > 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[heap_size];
        arr[heap_size] = temp;
        heap_size--;
        Max_Heapify(arr,0,heap_size);
    }
}
