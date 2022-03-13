#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<climits>
using namespace std;

int MCM(int values[],int low,int high)
{
    if(high<=low+1)
    {
        return 0;
    }

    int min=INT_MAX;

    for(int mid=low+1;mid<high;mid++)
    {
        int cost=MCM(values,low,mid);

        cost+=MCM(values,mid,high);

        cost+=values[low]*values[mid]*values[high];

        if(cost<min)
        {
            min=cost;
        }
    }
    return min;
}

int main(void)
{
    int values[]={10,30,5,60};

    int n=sizeof(values)/sizeof(values[0]);

    cout<<"Minimum Cost: "<<MCM(values,0,n-1);

    return 0;

}


