#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

int linear(int arr[],int n,int x)  //arr is given array, total number n, given fixed number x.
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            return i;
        }
    }
    return -1;
}

int main(void)
{
    int x=8;
    int arr[]={5,7,9,8,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int result=linear(arr,n,x);
    cout<<result<<endl;

}
