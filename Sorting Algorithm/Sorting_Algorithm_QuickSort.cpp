#include<bits/stdc++.h>
using namespace std;

int Partition(int A[],int low,int high)
{
    int pivot=A[high];
    int init=low;

    for(int i=low;i<high;i++)
    {
        if(A[i]<pivot)
        {
            swap(A[i],A[init]);
            init++;
        }
    }
    swap(A[init],A[high]);
    return init;
}

int QuickSort(int A[],int low,int high)
{
    if(low<high)
    {
        int part=Partition(A,low,high);

        QuickSort(A,low,part-1);
        QuickSort(A,part+1,high);
    }
}

int main(void)
{
    int A[]={2,4,3,1,5};
    QuickSort(A,0,4);
    for(int i=0;i<5;i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}
