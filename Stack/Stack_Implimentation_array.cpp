#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define MAX 101

class Stack{

private:
    int A[MAX];
    int top;

public:
    Stack()
    {
        top=-1; //initializing top as -1;
    }

    void Push(int x)
    {
        if(top==MAX-1)
        {
            cout<<"Error!"<<endl;
            return;
        }
        else{
            A[++top]=x;
        }
    }

    void Pop()
    {
        if(top==-1)
        {
            cout<<"Error!"<<endl;
            return;
        }
        else
        {
            top--;
        }
    }

    int Top()
    {
        return A[top];
    }

    int Isempty()
    {
        if(top==-1)
        {
            cout<<"Empty"<<endl;
            return 1;
        }
        else{
            return 0;
        }
    }

    int print()
    {
        cout<<"Stack: ";
        for(int i=0;i<=top;i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }


};


int main(void)
{
    Stack s;
    s.Push(2);s.print();
    s.Push(10);s.print();
    s.Push(5);s.print();
    s.Top();s.print();
    s.Pop();s.print();
}
