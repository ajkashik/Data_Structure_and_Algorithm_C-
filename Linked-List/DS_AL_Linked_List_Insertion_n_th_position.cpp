#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* head=NULL;

void inserting(int data,int n)
{
    node* temp=new node();
    temp->data=data;
    temp->next=NULL;

    if(n==1)
    {
        temp->next=head;
        head=temp;
        return;
    }

    node *temp1=head;

    for(int i=0;i<n-2;i++)
    {
        temp1=temp1->next;
    }

    temp->next=temp1->next;
    temp1->next=temp;
}

void print()
{
    node* temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(void)
{
    int i,data,n,elements;
    cout<<"Enter Number Of Elements: "<<endl;
    cin>>elements;
    for(i=0;i<elements;i++)
    {
        cout<<"Enter Data And Position: "<<endl;
        cin>>data>>n;
        inserting(data,n);
        cout<<"Linked-List: ";
        print();
        cout<<endl;
    }
    return 0;
}
