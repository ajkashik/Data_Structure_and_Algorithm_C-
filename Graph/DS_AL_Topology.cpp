#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>graph[100];
vector<int>result;
int runner[100];

void dfs(int start)
{
    runner[start]=1;
    for(int i=0;i<graph[start].size();i++)
    {
        int next=graph[start][i];
        if(runner[next]==0)
        {
            dfs(next);
        }
    }
    result.push_back(start);
}


int main(void)
{
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    for(int i=1;i<nodes;i++)
    {
        if(runner[i]==0)
        {
            dfs(i);
        }
    }

    reverse(result.begin(),result.end());

    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<endl;
    }
    return 0;
}
