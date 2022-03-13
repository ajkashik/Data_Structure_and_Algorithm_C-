#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<climits>
using namespace std;

int sum(int values[],int low,int high)
{
    int add=0;
    for(int mid=low;mid<=high;mid++)
    {
        add+=values[mid];
    }
    return add;
}

int optimal_cost(int values[],int low,int high)
{
    if(high<low)
    {
        return 0;
    }

    if(high==low)
    {
        return values[low];
    }

    int value_sum=sum(values,low,high);

    int min=INT_MAX;

    for(int mid=low;mid<=high;mid++)
    {
        int cost=optimal_cost(values,low,mid-1)+optimal_cost(values,mid+1,high);

        if(cost<min)
        {
            min=cost;
        }
    }
    return min+value_sum;

}

int optimal_search_tree(int nums[],int values[],int n)
{
    return optimal_cost(values,0,n-1);
}


int main(void)
{
    int nums[]={10,12,20};
    int values[]={34,8,50};

    int n=sizeof(nums)/sizeof(nums[0]);

    cout<<"Minimum cost is: "<<optimal_search_tree(nums,values,n)<<endl;

    return 0;

}
