#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define MAX 101

int memo[MAX][MAX];

int MCM(int values[],int low,int high)
{
    if(high<=low+1)
    {
        return 0;
    }

    int min=INT_MAX;

    if(memo[low][high]==0)
    {
        for(int mid=low+1;mid<high;mid++)
        {
            int cost=MCM(values,low,mid);

            cost+=MCM(values,mid,high);

            cost+=values[low]*values[mid]*values[high];

            if(min>cost)
            {
                min=cost;
            }
        }
        memo[low][high]=min;
    }
    return memo[low][high];
}

int main(void)
{
    int values[]={1,2,3,4};

    int n=sizeof(values)/sizeof(values[0]);

    cout<<"Minimum Cost: "<<MCM(values,0,n-1)<<endl;

    return 0;
}


