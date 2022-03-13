#include<bits/stdc++.h>
using namespace std;

#define maxx 101
int arr[maxx];
int top=-1;

void push(int x)
{
    if(top==maxx-1)
    {
        cout<<"Error!"<<endl;
        return;
    }
    arr[++top]=x;
}

void pop()
{
    if(top==-1)
    {
        cout<<"Error again!"<<endl;
        return;
    }
    top--;
}

void print()
{
    cout<<"Stack: "<<endl;
    for(int i=0;i<=top;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
}
int main(void)
{
    push(2);print();
    push(3);print();
    push(10);print();
    pop();print();
    push(12);print();


}

