#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};

void reversed(struct Node* head)
{
    if(head==NULL)
    {
        return;
    }
    reversed(head->next);
    cout<<head->data<<" ";

}

int main(void)
{
     Node* head=NULL;
     Node* second=NULL;
     Node* third=NULL;

     head=new Node();
     second=new Node();
     third=new Node();

     head->data=5;
     head->next=second;

     second->data=7;
     second->next=third;

     third->data=9;
     third->next=NULL;

     reversed(head);
}


