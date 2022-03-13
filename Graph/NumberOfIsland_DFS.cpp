#include<bits/stdc++.h>
#include<algorithm>
#include<cstring>
using namespace std;

#define M 10
#define N 10

int row[] = { -1, -1, -1, 0, 1, 0, 1, 1 };
int col[] = { -1, 1, 0, -1, -1, 1, 0, 1 };

bool isground(int mat[M][N],int row,int col,bool visited[M][N])
{
    return (col>=0) && (col<N) && (row>=0) && (row<M) && (mat[row][col]==true && visited[row][col]==false);
}

int dfs(int mat[M][N],bool visited[M][N],int roww,int coll)
{
    visited[roww][coll]=true;

    for(int i=0;i<8;i++)
    {
        if(isground(mat,roww+row[i],coll+col[i],visited))
        {
            dfs(mat,visited,roww+row[i],coll+col[i]);
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
		{ 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 }
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
                dfs(mat,visited,i,j);
                island++;
            }
        }
    }
    cout<<"Island: "<<island<<endl;
    return 0;
}
