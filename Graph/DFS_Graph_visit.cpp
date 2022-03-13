#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

#define MX 101

vector<int> graph[MX];
bool visited[MX];

int dfs(int source)
{
    visited[source]=1;

    for(int i=0;i<graph[source].size();i++)
    {
        int next=graph[source][i];

        if(visited[next]==0)
        {
            dfs(next);
        }
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

    int source;
    cout<<"Enter source: ";
    cin>>source;

    dfs(source);

    for(int i=1;i<=nodes;i++)
    {
        if(visited[i]==1)
        {
            cout<<i<<" is visited."<<endl;
        }
        else
        {
            cout<<i<<" is not visited."<<endl;        }
    }
    return 0;
}
