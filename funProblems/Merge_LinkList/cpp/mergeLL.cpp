/*
* FunctionLibrary
* Copyright (C) 2017  Mohit Raj <mohit.raj@st.niituniversity.in>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>
*
*/

#include <iostream>
#include <vector>
#include "linkedListLibrary.h"
#include "heapLibrary.h"

using namespace std;

int main()
{
    vector <int> sorted_list;
    int n,x,i, *temp, *copy, result, total_elements, counter = 0, o, *index;
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
        buildHeap(temp,o-1);
        result = extractMax(temp,o-1);
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
             updateHead(arr,index[g]);
        }
           
        delete temp;
        delete copy;
        counter++;
    }
    
    vector <int> :: iterator it;
    
    cout << "Merged Sorted List: ";
    for(it = sorted_list.begin(); it != sorted_list.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl << endl;

}
