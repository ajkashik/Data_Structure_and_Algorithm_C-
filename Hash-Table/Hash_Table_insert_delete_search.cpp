#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
using namespace std;

#define Size 7

struct node
{
    int data;
    struct node *next;
};

struct node *chain[Size];

void init()
{
    for(int i = 0; i < Size; i++)
        chain[i] = NULL;
}

void Insert(int value)
{
    struct node *newNode = new node();
    newNode->data = value;
    newNode->next = NULL;

    int key = value % Size;

    if(chain[key] == NULL)
    {
        chain[key] = newNode;
    }
    else
    {
        struct node *temp = chain[key];
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

int Delete(int value)
{
    int key = value % Size;
    struct node *temp = chain[key], *dealloc;
    if(temp != NULL)
    {
        if(temp->data == value)
        {
            dealloc = temp;
            temp = temp->next;
            delete dealloc;
            return true;
        }
        else
        {
            while(temp->next!=NULL)
            {
                if(temp->next->data == value)
                {
                    dealloc = temp->next;
                    temp->next = temp->next->next;
                    delete dealloc;
                    return true;
                }
                temp = temp->next;
            }
        }
    }
}

int Search(int value)
{
    int key = value % Size;
    struct node *temp = chain[key];
    while(temp!=NULL)
    {
        if(temp->data == value)
        {
            return true;
        }
        temp = temp->next;
    }
}

void print()
{
    int i;

    for(i = 0; i < Size; i++)
    {
        struct node *temp = chain[i];
        cout<<i<<"-->";
        while(temp!=NULL)
        {
            cout<<temp->data<<"-->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
}

int main()
{
    init();

    Insert(7);
    Insert(0);
    Insert(3);
    Insert(10);
    Insert(4);
    Insert(5);

    print();
    cout<<endl;

    Delete(10);
    print();

    cout<<endl;

    if(Search(3))
    {
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
    return 0;
}
