#include<bits/stdc++.h>
#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};

struct Node* reversed(struct Node* head)
{
    struct Node *current,*next,*prev;

    current=head;          //initializing current and previous
    prev=NULL;

    while(current!=NULL)
    {
        next=current->next;      //next to current-next to previous
        current->next=prev;

        prev=current;            // previous = current = next
        current=next;

    }
    head=prev;
    return head;
};

void print(struct Node* n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
}


int main(void)
{
    Node *head=NULL;       //initializing node
    Node *second=NULL;
    Node *third=NULL;

    head=new Node();      //creating node
    second=new Node();
    third=new Node();

    head->data=3;
    head->next=second;

    second->data=5;
    second->next=third;

    third->data=7;
    third->next=NULL;

    print(head);
    cout<<endl;

    head=reversed(head);
    print(head);

}
