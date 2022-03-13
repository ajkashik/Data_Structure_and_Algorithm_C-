#include<bits/stdc++.h>
#include<vector>
using namespace std;

const int MAX=300005;
vector<pair<int, int> > wt[MAX];
int fst[MAX],snd[MAX];


int main(void)
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        wt[w].push_back(make_pair(u,v));
    }
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<wt[i].size();j++)
        {
            int u=wt[i][j].first,v=wt[i][j].second;
            fst[v]=0;
        }
        for(int j=0;j<wt[i].size();j++)
        {
            int u=wt[i][j].first,v=wt[i][j].second;
            fst[v]=max(fst[v],snd[u]+1);
        }
        for(int j=0;j<wt[i].size();j++)
        {
            int u=wt[i][j].first,v=wt[i][j].second;
            snd[v]=max(snd[v],fst[v]);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,snd[i]);
    }
    cout<<ans<<endl;
    return 0;
}
