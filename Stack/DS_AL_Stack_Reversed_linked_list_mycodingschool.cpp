#include<bits/stdc++.h>
#include<stack>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};
struct Node* head;

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

void reversed()
{
    if(head==NULL)
    {
        return;
    }

    stack<struct Node*> s;

    Node* temp=head;

    while(temp!=NULL)
    {
        s.push(temp);
        temp=temp->next;
    }

    temp=s.top();
    head=temp;
    s.pop();

    while(!s.empty())
    {
        temp->next=s.top();
        s.pop();
        temp=temp->next;
    }
    temp->next=NULL;
}

void print()
{
    struct Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(void)
{
    inserting(2,1);
    inserting(3,2);
    inserting(4,1);print();
    cout<<endl<<"Reversed: "<<endl;
    reversed();
    print();
}
