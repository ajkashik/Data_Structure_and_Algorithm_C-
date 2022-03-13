#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define n 5

vector<int> graph[n];

int Print_graph(vector<int> graph[],int sizes)
{
    for(int i=0;i<sizes;i++)
    {
        cout<<i<<" -> ";
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(void)
{
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    Print_graph(graph,n);
    return 0;
}
