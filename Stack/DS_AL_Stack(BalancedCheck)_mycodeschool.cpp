#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool arepair(char open,char close)
{
    if(open=='(' && close==')')
    {
        return true;
    }
    else if(open=='{'&&close=='}')
        {
            return true;
        }
        else if(open=='['&&close==']')
        {
            return true;
        }
        return false;
}

bool checkbalanced(string x)
{
    stack<char> s;

    for(int i=0;i<x.length();i++)
    {
        if(x[i]=='(' || x[i]=='{' || x[i]=='[')
            {
                s.push(x[i]);
            }
            else if(s.empty()|| !arepair(s.top(),x[i]))
            {
                return false;
            }
            else
            {
                s.pop();
            }
    }
    return s.empty()? true:false;
}


int main(void)
{
    string s;
    cout<<"Enter string: "<<endl;
    cin>>s;
    if(checkbalanced(s))
    {
        cout<<"Balanced"<<endl;
    }
    else
    {
        cout<<"Not Balanced"<<endl;
    }

}
