#include<bits/stdc++.h>
using namespace std;

int activitySelection(int start[],int finish[],int Size)
{
    int i=0;
    cout<<i<<" ";
    for(int j=1;j<Size;j++)
    {
        if(start[j]>=finish[i])
        {
            cout<<j<<" ";
            i=j;
        }
    }
}

int main(void)
{
    int start[]={1,3,0,7,8};
    int finish[]={2,4,6,7,9};
    int n=5;
    activitySelection(start,finish,n);
    return 0;
}
