#include<bits/stdc++.h>
using namespace std;

#define maxx 101

class Stack
{
private:
    int arr[maxx];
    int top;
public:
    Stack()
    {
        top=-1;
    }
    void push(int x)
    {
        if(top==maxx-1)
        {
            cout<<"Error "<<endl;
            return;
        }
        arr[++top]=x;
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Error Again "<<endl;
            return;
        }
        top--;
    }

    int Top()
    {
        return arr[top];
    }

    int isempty()
    {
        if(top==-1)
        {
            return 1;
        }
        return 0;
    }
    void print()
    {
        for(int i=0;i<=top;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(void)
{
    Stack s;
    s.push(2);s.print();
    s.push(8);s.print();
    s.push(12);s.print();
    s.pop();s.print();
    s.push(10);s.print();
    return 0;
}
