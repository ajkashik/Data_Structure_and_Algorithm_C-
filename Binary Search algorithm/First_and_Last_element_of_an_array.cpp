#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int find_first_occurence(int arr[],int n,int x)
{
    int low=0;
    int high=n-1;
    int result=-1;

    while(low<=high)
    {
        int mid=(low+(high-low))/2;
        if(x==arr[mid])
        {
            result=mid;
            high=mid-1;
        }
        else if(x<arr[mid])
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return result;
}

int find_last_occurence(int arr[],int n,int x)
{
    int low=0;
    int high=n-1;
    int result=-1;

    while(low<=high)
    {
        int mid=low+(high-low);
        if(arr[mid]==x)
        {
            result=mid;
            low=mid+1;
        }
        else if(x<arr[mid])
        {
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return result;
}

int main(void)
{
    int arr[]={2,3,3,3,5,9,10,12};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=3;

    int index=find_first_occurence(arr,n,x);

    if(index!=-1)
    {
        cout<<index<<endl;
    }
    else
    {
        cout<<"Error"<<endl;
    }

    int index2=find_last_occurence(arr,n,x);

    if(index2!=-1)
    {
        cout<<index2<<endl;
    }
    else
    {
        cout<<"Error"<<endl;
    }

    return 0;
}
