#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

bool utilbst(Node* root,int minvalue,int maxvalue)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->data>minvalue && root->data<maxvalue && utilbst(root->left,minvalue,root->data) && utilbst(root->right,root->data,maxvalue))
    {
        return true;
    }
    else
    {
        false;
    }
}

bool isbst(Node* root)
{
    return utilbst(root,INT_MIN,INT_MAX);
}

Node* Insert(struct Node* root,int data)
{
    if(root==NULL)
    {
        root=new Node();
        root->data=data;
        root->left=root->right=NULL;
    }
    else if(data<=root->data)
    {
        root->left=Insert(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=Insert(root->right,data);
    }
    return root;
}

int main(void)
{
    Node* root=NULL;
    root=Insert(root,15);root=Insert(root,20);
    root=Insert(root,12);root=Insert(root,25);
    root=Insert(root,8);root=Insert(root,16);
    root=Insert(root,14);
    if(isbst(root))
    {
        cout<<"YES!"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}
