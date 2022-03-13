#include<bits/stdc++.h>
using namespace std;

int InsertionSort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int value=arr[i];
        int key=i;
        while(key>0 && arr[key-1]>value)
        {
            arr[key]=arr[key-1];
            key=key-1;
        }
        arr[key]=value;
    }
}


int main(void)
{
    int arr[]={1,3,2,5,4};
    InsertionSort(arr,5);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
