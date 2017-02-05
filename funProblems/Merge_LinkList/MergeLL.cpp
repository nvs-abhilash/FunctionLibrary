#include <iostream>
#include <vector>
#include "traverseLL.cpp"
#include "Heap_Sort.cpp"
using namespace std;
int main()
{
    vector <int> sorted_list;
    int n,x,i,k = 0, *temp, *copy, result, total_elements, counter = 0, o, *index;
    cout << "Enter the number of Linked lists : ";
    cin >> n;
    total_elements = 0;
    node *arr[n];
    for(i = 0; i < n; i++)
    {
        cout << "Enter the size of list " << i+1 << ":";
        cin >> x;
        total_elements = total_elements + x;
        arr[i] = makeLL(x);
    }
    
    node *t;
   
    while(counter != total_elements)
    {
        temp = new int[n];
        copy = new int[n];
        index = new int[n];
        o = 0;
        for(i = 0; i < n; i++)
        {
            t = arr[i];
            if(t != NULL)
            {
                temp[o] = t->data;
                copy[o] = t->data;
                index[o] = i;
                o++;
            }
        }
        Build_Heap(temp,o-1);
        result = Extract_Max(temp,o-1);
        sorted_list.push_back(result);
        int g;
        //TODO Implement Binary Search
        for(g = 0; g < n; g++)
        {
            if(copy[g] == result)
            {
                 break;
            }
        }
        if(arr[index[g]] != NULL)
        {
             Update_Head(arr,index[g]);
        }
           
        delete temp;
        delete copy;
        counter++;
    }
    
    vector <int> :: iterator it;
    
    for(it = sorted_list.begin(); it != sorted_list.end(); it++)
    {
        cout << *it << " ";
    }
}