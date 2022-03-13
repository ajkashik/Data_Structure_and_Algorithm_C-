#include<iostream>
using namespace std;
void swap(int *p,int *q)
{
    int temp=*p;
    *p=*q;
    *q=temp;
}
void selection(int arr[],int n)
{
    int i,j,min_index;
    for(i=0;i<n;i++)
    {
       min_index=i;
       for(j=i+1;j<n;j++)
       {
           if(arr[j]<arr[min_index])
           {
               min_index=j;
           }
       }
       swap(&arr[min_index],&arr[i]);
    }
}
void print(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(void)
{
    int arr[]={45,56,78,34,23};
    int n=sizeof(arr)/sizeof(arr[0]);
    selection(arr,n);
    print(arr,n);
    return 0;
}
