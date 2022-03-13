#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binary_search_iter(int arr[],int sizes,int element)
{
    int low=0,high=sizes-1;

    while(low<=high)
    {
        int mid=low+(high-low)/2;

        if(arr[mid]==element)
        {
            return mid;
        }
        else if(arr[mid]<element)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
}

int main(void)
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int arr[]={2,4,5,6,8,9,10,15};
    int sizes=sizeof(arr)/sizeof(arr[0]);

    int index=binary_search_iter(arr,sizes,10);

    if(index!=-1)
    {
        cout<<index<<endl;
    }
    else
    {
        cout<<"Error!"<<endl;
    }
    return 0;
}
