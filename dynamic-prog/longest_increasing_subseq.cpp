#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

int long_in_subseq(int arr[],int n)
{
    int list[n];
    list[0]=1;

    for(int i=1;i<n;i++)
    {
        list[i]=1;
        for(int j=0;j<i;j++)
        {
            if(arr[i] > arr[j] && list[i] < list[j]+1)
            {
                list[i]=list[j]+1;
            }
        }
    }
    return *max_element(list,list+n);
}


int main(void)
{
    int arr[]={5,4,8,7,1,9};

    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<"answer: "<<long_in_subseq(arr,n)<<endl;

    return 0;
}
