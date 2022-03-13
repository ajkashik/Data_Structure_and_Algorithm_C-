#include<bits/stdc++.h>
using namespace std;

#define MX 105
#define INF 100000000

struct Node
{
    int val;
    int cost;
};

vector<Node> graph[MX];
bool vis[MX];
int dist[MX];

void reset()
{
    for(int i=0;i<MX;i++)
    {
        graph[i].clear();
        vis[i]=0;
        dist[i]=INF;
    }
}

class cmp
{
public:
    bool operator()(Node &A,Node &B)
    {
        if(A.cost>B.cost)
        {
            return true;
        }
        return false;
    }
};

void dijkstra(int source)
{
    priority_queue<Node, vector<Node>, cmp> PQ;
    PQ.push({source,0});

    while(!PQ.empty())
    {
        Node current=PQ.top();
        PQ.pop();

        int val=current.val;
        int cost=current.cost;

        if(vis[val]==1)
        {
            continue;
        }

        dist[val]=cost;
        vis[val]=1;

        for(int i=0;i<graph[val].size();i++)
        {
            int nxt=graph[val][i].val;
            int nxtcost=graph[val][i].cost;

            if(vis[nxt]==0)
            {
                PQ.push({nxt,cost+nxtcost});
            }
        }
    }
}


int main(void)
{
    reset();

    int nodes,edges;
    cin>>nodes>>edges;

    for(int i=1;i<=edges;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }

    int source;
    cout<<"Enter Sources: ";
    cin>>source;

    dijkstra(source);

    for(int i=1;i<=nodes;i++)
    {
        cout<<"Nodes: "<<i<<" Distance: ";
        if(dist[i]==INF)
        {
            cout<<"inf"<<endl;
        }
        else{
            cout<<dist[i]<<endl;
        }
    }
    return 0;
}
