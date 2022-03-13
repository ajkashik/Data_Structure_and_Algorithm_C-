#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

struct Node* top;

void push(int x)
{
    struct Node* temp=new Node();
    temp->data=x;
    temp->next=top;
    top=temp;
}

void pop()
{
    struct Node* temp;

    if(top==NULL)
    {
        return;
    }
    temp=top;
    top=top->next;
    delete temp;
}
void print()
{
    struct Node* temp=top;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
  cout<<endl;
}
int main(void)
{
    push(2);
    push(3);print();
    push(5);
    push(7);print();
    pop();print();
}
