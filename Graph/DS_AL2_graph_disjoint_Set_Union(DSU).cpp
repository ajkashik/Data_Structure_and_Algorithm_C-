#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define MX 100
int parent[MX];

void makeset(int u)
{
    parent[u]=u;
}

void init()
{
    for(int i=0;i<8;i++)
    {
        makeset(i);
    }
}

int Find(int u)
{
    if(u==parent[u])
    {
        return u;
    }
    return parent[u]=Find(parent[u]);
}

void Union(int u,int v)
{
    int p=Find(u);
    int q=Find(v);
    if(p!=q)
    {
        parent[q]=p;
    }
}

bool isFriend(int u,int v)
{
    int p=Find(u);
    int q=Find(v);
    return (p==q);
}

int main(void)
{
    init();
    Union(2,3);
    Union(3,4);
    Union(4,7);
    Union(5,6);
    if(isFriend(2,7))
    {
        cout<<"Friend"<<endl;
    }
    else
    {
        cout<<"Not Friend"<<endl;
    }
    return 0;
}

