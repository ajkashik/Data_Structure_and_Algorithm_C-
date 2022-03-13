#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int Binary_Search(int A[],int N,int X)
{
    int low=0;
    int high=N-1;
    while(low<=high)
    {
        int mid=(high-low)+low/2;
        if(X==A[mid])
        {
            return mid;
        }
        else if(X<A[mid])
        {
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}


int main(void)
{
    int A[]={3,4,5,6,9,12};
    int N=sizeof(A)/sizeof(A[0]);
    int X=12;
    int index=Binary_Search(A,N,X);
    if(index!=-1)
    {
        cout<<"Index Is: "<<index<<endl;
    }
    else{
        cout<<"Not Available"<<endl;
    }
    return 0;
}
