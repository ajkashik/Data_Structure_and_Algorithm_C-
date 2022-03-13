#include<bits/stdc++.h>
using namespace std;

#define MX 101

vector<int>graph[MX];
bool vis[MX];
int dist[MX];

void bsf(vector<int>sources)
{
    queue<int> Q;
    for(int i=0;i<sources.size();i++)
    {
        int source=sources[i];
        vis[source]=1;
        dist[source]=0;
        Q.push(source);
    }

    while(!Q.empty())
    {
        int current=Q.front();
        Q.pop();

        for(int i=0;i<graph[current].size();i++)
        {
            int next=graph[current][i];

            if(vis[next]==0)
            {
                vis[next]=1;
                dist[next]=dist[current]+1;
                Q.push(next);
            }
        }
    }
}





int main(void)
{
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=1;i<=edges;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int numberofsources;
    cin>>numberofsources;

    vector<int> sources;

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
        cout<<"Distance of "<<i<<" is: "<<dist[i]<<endl;
    }

    return 0;
}
