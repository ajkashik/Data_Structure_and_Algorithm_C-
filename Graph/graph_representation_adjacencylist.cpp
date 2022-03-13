#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> graph[5];

void print_adj_list(vector<int>graph[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<i<<"-> ";
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
    print_adj_list(graph,5);
    return 0;
}
