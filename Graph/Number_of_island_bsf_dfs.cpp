#include<bits/stdc++.h>
#include<cstring>
#include<queue>
using namespace std;

#define M 10
#define N 10

int row[] = { -1, -1, -1, 0, 1, 0, 1, 1 };
int col[] = { -1, 1, 0, -1, -1, 1, 0, 1 };


bool isground(int mat[M][N],int i,int j,bool visited[M][N])
{
    return (i>=0) && (i<M) && (j>=0) && (j<N) && (mat[i][j]==true && visited[i][j]==false);
}


int bfs(int mat[M][N],bool visited[M][N],int i,int j)
{
    queue<pair<int, int> > Q;
    Q.push(make_pair(i,j));

    visited[i][j]=true;

    while(!Q.empty())
    {
        int x=Q.front().first;
        int y=Q.front().second;
        Q.pop();

        for(int t=0;t<8;t++)
        {
            if(isground(mat,x+row[t],y+col[t],visited))
            {
                visited[x+row[t]][y+col[t]]=true;
                Q.push(make_pair(x+row[t],y+col[t]));
            }
        }
    }
}


int main(void)
{
    int mat[M][N]=
	{
		{ 1, 0, 1, 0, 0, 0, 1, 1, 1, 1 },
		{ 0, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
		{ 1, 1, 1, 1, 0, 0, 1, 0, 0, 0 },
		{ 1, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 },
		{ 0, 1, 0, 1, 0, 0, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 0, 1, 1, 1, 0, 0 },
		{ 0, 0, 0, 1, 0, 0, 1, 1, 1, 0 },
		{ 1, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
		{ 1, 1, 1, 1, 0, 0, 0, 1, 0, 1 }
	};


    bool visited[M][N];
    memset(visited,0,sizeof(visited));

    int island=0;

    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(mat[i][j]==true && visited[i][j]==false)
            {
                bfs(mat,visited,i,j);
                island++;
            }
        }
    }
    cout<<"Island: "<<island<<endl;
    return 0;
}


