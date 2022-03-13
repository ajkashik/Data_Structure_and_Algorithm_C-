#include<stdbool.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define V 4
void print_solution(int color[]);

bool is_safe(int v,bool graph[V][V],int color[],int c)
{
    for(int i=0;i<V;i++)
    {
        if(graph[v][i]==true && c==color[i])
        {
            return false;
        }
    }
    return true;
}

bool graph_coloring_util(int v,bool graph[V][V],int color[],int m)
{
    if(v==V)
    {
        return true;
    }
    for(int c=1;c<=m;c++)
    {
        if(is_safe(v,graph,color,c)==true)
        {
            color[v]=c;

            if(graph_coloring_util(v+1,graph,color,m))
            {
                return true;
            }

            color[v]=0;
        }
    }

    return false;
}

bool graph_coloring(bool graph[V][V],int m)
{
    int color[V];

    for(int i=0;i<V;i++)
    {
        color[i]=0;
    }

    if(graph_coloring_util(0,graph,color,m)==false)
    {
        cout<<"Solution Doesn't Exist"<<endl;
        return false;
    }

    print_solution(color);
    return true;
}

void print_solution(int color[])
{
    cout<<"Solution Exist: Following Color"<<endl;
    for(int i=0;i<V;i++)
    {
        cout<<color[i]<<" ";
    }
    cout<<endl;
}

int main(void)
{
    bool graph[V][V]={{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}};
    int m=1;
    graph_coloring(graph,m);
    return 0;
}
