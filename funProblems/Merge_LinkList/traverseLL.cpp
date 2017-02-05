#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*head;

void Update_Head(node *arr[],int x)
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
    head = new node;
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
