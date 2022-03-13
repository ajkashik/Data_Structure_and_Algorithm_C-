#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int start;
    int finish;
};

bool cmp(Node a,Node b)
{
    return(a.finish < b.finish);
}

int activitySelection(Node arr[],int n)
{
    sort(arr,arr+n,cmp);

    int i=0;
    cout<<"("<<arr[i].start<<", "<<arr[i].finish<<")";

    for(int j=1;j<n;j++)
    {
        if(arr[j].start >= arr[i].finish)
        {
            cout<<"("<<arr[j].start<<", "<<arr[j].finish<<")";
            i=j;
        }
    }
}


int main(void)
{
    Node arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    int n=6;
    activitySelection(arr,n);
    return 0;
}
