#include<bits/stdc++.h>
#include<stack>
#include<algorithm>
using namespace std;

int postfixeval(string exp)
{
    stack<int> s;

    for(int i=0;i<exp.length();i++)
    {
        if(exp[i]>='0' && exp[i]<='9')
        {
            s.push(exp[i]-'0');
        }
        else
        {
            int x=s.top();
            s.pop();

            int y=s.top();
            s.pop();

            if(exp[i]=='+')
            {
                s.push(y+x);
            }
            else if(exp[i]=='-')
            {
                s.push(y-x);
            }
            else if(exp[i]=='*')
            {
                s.push(y*x);
            }
            else if(exp[i]=='/')
            {
                s.push(y/x);
            }
        }
    }
    return s.top();
}

int main(void)
{
    string exp;
    cin>>exp;
    cout<<postfixeval(exp)<<endl;
    return 0;
}
