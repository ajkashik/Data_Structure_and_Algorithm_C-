#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int max(int a,int b)
{
    return (a>b)?a:b;
}

int longest_common_subsequence(string S1,string S2,int x,int y)
{
    if(x==0 || y==0)
    {
        return 0;
    }

    if(S1[x-1]==S2[y-1])
    {
        return longest_common_subsequence(S1,S2,x-1,y-1)+1;
    }

    return max(longest_common_subsequence(S1,S2,x,y-1),longest_common_subsequence(S1,S2,x-1,y));
}

int main(void)
{
    string S1="ANIKA";
    string S2="SABIR";

    int x=S1.length();
    int y=S2.length();

    cout<<"Answer: "<<longest_common_subsequence(S1,S2,x,y);

    return 0;
}
