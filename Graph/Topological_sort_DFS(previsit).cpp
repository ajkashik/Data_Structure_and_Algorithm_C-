#include<bits/stdc++.h>
using namespace std;

vector<int> result;
vector<int> graph[101];
bool visited[101];

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
    result.push_back(source);
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
    }
    for(int i=1;i<=nodes;i++)
    {
        if(visited[i]==0)
        {
            dfs(i);
        }
    }
    reverse(result.begin(),result.end());

    cout<<"Topological Sort: "<<endl;
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}
