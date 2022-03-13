#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

void print();
void inserting(int data,int n);
void deleting(int n);

struct Node* head;

int main(void)
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    head=NULL;
    inserting(4,1);
    inserting(3,1);
    inserting(5,3);
    inserting(2,1);
    inserting(7,1);
    print();
    cout<<endl;
    deleting(4);
    print();
}

void print()
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
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

    Node* temp2=head;

    for(int i=0;i<n-2;i++)
    {
        temp2=temp2->next;
    }

    temp1->next=temp2->next;
    temp2->next=temp1;

}

void deleting(int n)
{
    struct Node* temp1=head;

    if(n==1)
    {
        head=temp1->next;
        delete temp1;
        return;
    }

    for(int i=0;i<n-2;i++)
    {
        temp1=temp1->next;
    }

    struct Node* temp2=temp1->next;
    temp1->next=temp2->next;
    delete temp2;
}







