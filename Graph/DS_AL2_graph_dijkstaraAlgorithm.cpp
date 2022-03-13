#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define MX 101
#define INF 1000000000
struct node
{
    int val;
    int cost;
};

vector<node> G[MX];
bool vis[MX];
int dist[MX];

void reset()
{
    for(int i=0;i<MX;i++)    //visit all the elements and clear,visit clear to non visit and distance INF. for reset;
    {
        G[i].clear();
        vis[i]=0;
        dist[i]=INF;
    }
}

class cmp       //take a comparator that push in  priority_queue first the bigger element.
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

void dijkstra(int source)
{
    priority_queue<node, vector<node>,cmp> Q;   // first push taken source and the value of 0;
    Q.push({source,0});

    while(!Q.empty())
    {
        node current =Q.top();  //take a current node where the top element placed and then pop;
        Q.pop();

        int val=current.val;    // then update the value and cost;
        int cost=current.cost;

        if(vis[val]==1)    //if node is visited then continue to the next
        {
            continue;
        }
        dist[val]=cost;   //otherwise the cost becomes the distance of value. and then value becomes visited;
        vis[val]=1;

        for(int i=0;i<G[val].size();i++)   //now visit all the neighbor with value and cost;
        {
            int nxt=G[val][i].val;
            int nxtcost=G[val][i].cost;

            if(vis[nxt]==0)    //if not visited then push into th queue the value of cost of next-value;
            {
                Q.push({nxt,cost+nxtcost});
            }
        }

    }
}


int main(void)
{
    reset();

    int nodes,edges;
    cin>>nodes>>edges;

    for(int i=0;i<edges;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        G[u].push_back({v,w});
    }

    cout<<"Enter source: ";
    int source;
    cin>>source;

    dijkstra(source);

    for(int i=1;i<=nodes;i++)
    {
        cout<<"Nodes: "<<i<<" Distance: ";
        if(dist[i]==INF)
        {
            cout<<"Inf"<<endl;
        }
        else
        {
            cout<<dist[i]<<endl;
        }
    }
    return 0;
}
