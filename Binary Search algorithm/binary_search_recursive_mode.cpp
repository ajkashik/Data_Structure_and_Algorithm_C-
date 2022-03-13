#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int Binary_Search(int A[],int low,int high,int X)
{
    if(low>high)
    {
        return -1;
    }

    int mid=low+(high-low)/2;

    if(X<A[mid])
    {
        return Binary_Search(A,low,mid-1,X);
    }
    else if(X>A[mid])
    {
        return Binary_Search(A,mid+1,high,X);
    }
    else
    {
        return mid;
    }
}

int main(void)
{
    int A[]={2,4,5,7,8,9};
    int X=5;
    int n=sizeof(A)/sizeof(A[0]);
    int index=Binary_Search(A,0,n-1,X);

    if(index!=-1)
    {
        cout<<"Index Is: "<<index<<endl;
    }
    else
    {
        cout<<"Not Valid"<<endl;
    }

    return 0;

}
