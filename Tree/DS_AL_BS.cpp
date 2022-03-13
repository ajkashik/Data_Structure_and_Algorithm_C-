#include<bits/stdc++.h>
using namespace std;

int binary(int arr[],int l,int r,int x)
{
    if(l<=r)
    {
        int m=l+(r-l)/2;
        if(arr[m]==x)
        {
            return m;
        }
        if(arr[m]>x)
        {
            return binary(arr,l,m-1,x);
        }
        return binary(arr,m+1,r,x);
    }
    return -1;
}

int main(void)
{
    int x=10;
    int arr[]={2,4,6,8,10,12,14};
    int n=sizeof(arr)/sizeof(arr[0]);
    int result=binary(arr,0,n-1,x);
    cout<<result<<endl;
}
