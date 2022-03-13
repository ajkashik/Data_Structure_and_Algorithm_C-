#include<bits/stdc++.h>
using namespace std;
#define MX 101
#define INF 1000000000

struct node
{
    int val;
    int cost;
};

vector<node> G[MX];
int dist[MX];
bool vis[MX];

void reset()
{
    for(int i=0;i<MX;i++)
    {
        G[i].clear();
        vis[i]=0;
        dist[i]=INF;
    }
}

class cmp
{
public:
    bool operator()(node &A,node &B)
    {
        if(A.cost>B.cost)
        {
            return true;
        }
        return false;
    }
};

int dijkstra(int source,int time)
{
    priority_queue<node,vector<node>,cmp> Q;
    Q.push({source,0});

    int cnt=0;

    while(!Q.empty())
    {
        node current=Q.top();
        Q.pop();

        int val=current.val;
        int cost=current.cost;

        if(vis[val]==1)
        {
            continue;
        }
        dist[val]=cost;
        vis[val]=1;

        if(dist[val]<=time)
        {
            cnt++;
        }

        for(int i=0;i<G[val].size();i++)
        {
            int nxt=G[val][i].val;
            int nxtcost=G[val][i].cost;

            if(vis[nxt]==0)
            {
                Q.push({nxt,cost+nxtcost});
            }
        }
    }
}
int main(void)
{
    int test;
    cin>>test;
    for(int i=0;i<test;i++)
    {
        reset();
        int n,e,t;
        cin>>n>>e>>t;

        int m;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            G[v].push_back({u,w});
        }
        int ans=dijkstra(e,t);
        if(i>1){cout<<endl;}
        cout<<ans<<endl;
    }
}
