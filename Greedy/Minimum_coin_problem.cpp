#include<bits/stdc++.h>
using namespace std;

#define MX 101
int result[MX];

int minimumCoin(int arr[],int Size,int value)
{
    int Count=0;
    for(int i=0;i<Size;i++)
    {
        while(value>=arr[i])
        {
            value=value-arr[i];
            result[Count]=arr[i];
            Count++;
        }
        if(value==0)
        {
            break;
        }
    }
    return Count;
}


int main(void)
{
    int arr[]={5,10,15,20,25};
    int value=105;
    int Size=5;

    reverse(arr,arr+Size);

    int Min=minimumCoin(arr,Size,value);
    cout<<Min<<endl;

    for(int i=0;i<Min;i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;
}
