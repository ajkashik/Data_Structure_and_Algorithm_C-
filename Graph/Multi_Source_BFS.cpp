#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define MX 101

vector<int> graph[MX];
bool visited[MX];
int dist[MX];

int bsf(vector<int> sources)
{
    queue<int> Q;
    for(int i=0;i<sources.size();i++)
    {
        int source=sources[i];
        visited[source]=1;
        dist[source]=0;
        Q.push(source);
    }

    while(!Q.empty())
    {
        int node=Q.front();
        Q.pop();

        for(int i=0;i<graph[node].size();i++)
        {
            int next=graph[node][i];
            if(visited[next]==0)
            {
                visited[next]=1;
                dist[next]=dist[node]+1;
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

    vector<int> sources;

    int numberofsources;
    cin>>numberofsources;

    for(int i=0;i<numberofsources;i++)
    {
        int source;
        cin>>source;
        sources.push_back(source);
    }

    bsf(sources);

    for(int i=1;i<=nodes;i++)
    {
        if(dist[i]==0)
        {
            continue;
        }
        cout<<"Distance of "<<i<< "is: "<<dist[i]<<endl;
    }
    return 0;
}
