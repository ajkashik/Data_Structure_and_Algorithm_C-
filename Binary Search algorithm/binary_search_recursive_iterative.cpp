#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binary_search_recur(int arr[],int low,int high,int element)
{
    while(low<=high)
    {
        int mid=(high-low)+low/2;

        if(arr[mid]==element)
        {
            return mid;
        }
        else if(arr[mid]<element)
        {
            return binary_search_recur(arr,mid+1,high,element);
        }
        else
        {
            return binary_search_recur(arr,low,mid-1,element);
        }
    }
    return -1;
}

int main(void)
{
    int arr[]={2,5,7,8,9,10,15};
    int sizes=sizeof(arr)/sizeof(arr[0]);

    int index=binary_search_recur(arr,1,sizes,10);

    if(index!=-1)
    {
        cout<<index<<endl;
    }
    else
    {
        cout<<"ERROR!"<<endl;
    }
    return 0;
}
