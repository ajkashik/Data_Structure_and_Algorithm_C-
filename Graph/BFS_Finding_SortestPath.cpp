#include<bits/stdc++.h>
using namespace std;

#define MX 101

bool visited[MX];
int dist[MX];
vector<int> graph[MX];

int bfs(int source)
{
    queue<int> Q;
    visited[source]=1;
    dist[source]=0;
    Q.push(source);

    while(!Q.empty())
    {
        int temp=Q.front();
        Q.pop();

        for(int i=0;i<graph[temp].size();i++)
        {
            int next=graph[temp][i];
            if(visited[next]==0)
            {
                visited[next]=1;
                dist[next]=dist[temp]+1;
                Q.push(next);
            }
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
    cin>>source;

    bfs(source);

    for(int i=1;i<=nodes;i++)
    {
        cout<<"Distance of " <<i<<" is: "<<dist[i]<<endl;
    }
    return 0;
}
