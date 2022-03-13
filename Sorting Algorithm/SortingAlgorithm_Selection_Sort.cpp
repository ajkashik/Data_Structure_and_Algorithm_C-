#include<bits/stdc++.h>
using namespace std;

int SelectionSort(int A[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minimum=i;
        for(int j=i+1;j<n;j++)
        {
            if(A[j]<A[minimum])
            {
                minimum=j;
            }
        }
        int temp=A[i];
        A[i]=A[minimum];
        A[minimum]=temp;
    }
}

int main(void)
{
    int A[]={2,1,5,4,3};
    SelectionSort(A,5);
    for(int i=0;i<5;i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}
