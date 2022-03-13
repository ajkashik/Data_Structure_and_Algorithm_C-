#include<bits/stdc++.h>
using namespace std;

int graph[5][5];

int print_matrix(int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<i<<"-> ";
        for(int j=0;j<n;j++)
        {
            if(graph[i][j]==1)
            {
                cout<<j<<" ";
            }
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
        graph[u][v]=1;
        graph[v][u]=1;
    }

    print_matrix(5);

    return 0;
}
