#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};
struct Node* head;     //global variable

void inserting(int data,int n);
void print();


int main(void)
{
    head=NULL;         //initializing as NULL
    inserting(2,1);
    inserting(3,2);
    inserting(4,3);
    inserting(5,2);
    print();
}

void inserting(int data,int n)
{
    Node* temp1=new Node();
    temp1->data=data;
    temp1->next=NULL;

    if(n==1)
    {
        temp1->next=head;
        head=temp1;
        return;
    }

    Node* temp2=head;      //start temp2 as head

    for(int i=0;i<n-2;i++)
    {
        temp2=temp2->next;
    }

    temp1->next=temp2->next;
    temp2->next=temp1;
}

void print()
{
    Node* temp=head;       //start temp as head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}







