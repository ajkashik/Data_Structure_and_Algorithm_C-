#include<bits/stdc++.h>
using namespace std;

#define MAX 101

class Queue{
private:
    int a[MAX];
    int fronted,rear;
public:
    Queue()
    {
        fronted=-1;
        rear=-1;
    }
    bool isempty()
    {
        return (fronted==-1 && rear==-1);
    }
    bool isfull()
    {
        return (rear+1)%MAX==fronted? true:false;
    }
    void Enqueue(int x)
    {
        cout<<"Enqueue: "<<x<<endl;

        if(isfull())
        {
            cout<<"Error:Queue is Full"<<endl;
            return;
        }
        if(isempty())
        {
            fronted=rear=0;
        }
        else{
            rear=(rear+1)%MAX;
        }
        a[rear]=x;
    }
    void Dequeue()
    {
        cout<<"Dequeue "<<endl;

        if(isempty())
        {
            cout<<"Error: Queue Is Empty"<<endl;
            return;
        }
        else if(fronted==rear)
        {
            rear=fronted=-1;
        }
        else
        {
            fronted=(fronted+1)%MAX;
        }
    }
    int front()
    {
        if(fronted==-1)
        {
            cout<<"Error: Cannot Return"<<endl;
            return -1;
        }
        return a[fronted];
    }
    void print()
    {
        int count=(rear+MAX-fronted)%MAX+1;
        cout<<"Queue: ";
        for(int i=0;i<count;i++)
        {
            int index=(fronted+i)%MAX;
            cout<<a[index]<<" ";
        }
        cout<<endl;
    }

};



int main(void)
{
    Queue Q;
    Q.Enqueue(2);Q.print();
    Q.Enqueue(3);Q.print();
    Q.Enqueue(5);Q.print();
    Q.Enqueue(7);Q.print();
    Q.Dequeue();Q.print();
    Q.Enqueue(9);Q.print();
}
