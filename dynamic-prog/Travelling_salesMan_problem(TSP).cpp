#include<bits/stdc++.h>
#include<iostream>
#include<limits>
#include<algorithm>
using namespace std;

#define N 5

int TSP(int cost[][N])
{
    int byke[N];

    for(int i=0;i<N;i++)
    {
        byke[i]=cost[0][i];
    }

    bool visited=false;

    while(!visited)
    {
        visited=true;

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(byke[i]>byke[j]+cost[j][i])
                {
                    byke[i]=byke[j]+cost[j][i];

                    visited=false;
                }
            }
        }
    }
    return byke[N-1];
}



int main(void)
{
    int cost[N][N]={{ 0, 25, 20, 10, 105 },
        { 20, 0, 15, 80, 80 },
        { 30, 15, 0, 70, 90 },
        { 10, 10, 50, 0, 100 },
        { 40, 50, 5, 10, 0 }};

    cout<<"Minimum cost: "<<TSP(cost)<<endl;

    return 0;

}
