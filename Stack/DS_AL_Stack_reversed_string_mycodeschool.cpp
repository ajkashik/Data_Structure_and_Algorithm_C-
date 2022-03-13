#include<bits/stdc++.h>
#include<stack>
using namespace std;

void reversed(char *c,int n)
{
    stack<char> s;
    for(int i=0;i<n;i++)
    {
        s.push(c[i]);
    }

    for(int i=0;i<n;i++)
    {
        c[i]=s.top();
        s.pop();
    }
}

int main(void)
{
    char c[100];
    cout<<"Enter string: "<<endl;
    gets(c);
    reversed(c,strlen(c));
    cout<<endl<<"Reversed: "<<endl;
    cout<<c<<endl;
}
