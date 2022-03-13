#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

struct Node* fronting=NULL;
struct Node* rear=NULL;

void Enqueue(int x)
{
    struct Node* temp=new Node();
    temp->data=x;
    temp->next=NULL;

    if(fronting==NULL && rear==NULL)
    {
        fronting=rear=temp;
        return;
    }
    rear->next=temp;
    rear=temp;
}

void Dequeue()
{
    struct Node* temp=fronting;
    if(fronting==NULL)
    {
        cout<<"Queue Is NULL"<<endl;
        return;
    }
    if(fronting==rear)
    {
        fronting=rear=NULL;
    }
    else{
        fronting=fronting->next;
    }
    delete temp;
}

int Front()
{
    if(fronting==NULL)
    {
        cout<<"Error!"<<endl;
    }
    return fronting->data;
}
void print()
{
    struct Node* temp=fronting;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


int main(void)
{
    Enqueue(2);print();
    Enqueue(6);print();
    Enqueue(7);print();
    Enqueue(9);print();
    Dequeue();print();
    Enqueue(11);print();
}
