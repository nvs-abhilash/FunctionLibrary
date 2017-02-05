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
#include "linkedListLibrary.h"

using namespace std;

void updateHead(node *arr[],int x)
{
    arr[x] = arr[x]->next; 
}
void traverse(node *arr[],int n)
{
    cout << "GENERATING LIST..." << endl;
    int i = 0;
    while(i < n)
    {
        node *t;
        cout << "Printing list " << i+1 << ": ";
        for(t = arr[i]; t!= NULL; t = t->next)
        {
            cout << t->data << "  ";
        }
        cout << endl;
        i++;
    }
}

node *makeLL(int n)
{
    int x, i = 0;;
    struct node *temp, *newnode;
    node *head = new node;
    temp = new node;
    newnode = new node;
    cout << "Enter the value for node " << i+1 << ": ";
    cin >> x; 
    head->data = x;
    head->next = NULL;
    temp = head;
    for(i = 1; i < n; i++)
    {
        if(head == NULL)
        cout << "Head is not allocated memory" << endl;

        else
        {
            cout << "Enter the value for node " << i+1 << ": ";
            cin >> x; 
            newnode = new node;
            newnode->data = x;
            newnode->next = NULL;
            temp->next = newnode;
            temp = temp->next;
        }
    }
    return head;
}   
