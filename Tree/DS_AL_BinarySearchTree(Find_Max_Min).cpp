#include<bits/stdc++.h>
using namespace std;

struct bstnode
{
    int data;
    struct bstnode* left;
    struct bstnode* right;
};

struct bstnode* getnode(int data)
{
    struct bstnode* newnode=new bstnode();
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
};

bstnode* Insert(struct bstnode* root,int data)
{
    if(root==NULL)
    {
        root=getnode(data);
    }
    else if(data<=root->data)
    {
        root->left=Insert(root->left,data);
    }
    else
    {
        root->right=Insert(root->right,data);
    }
    return root;
}

bool Search(struct bstnode* root,int data)
{
    if(root==NULL)
    {
        return false;
    }
    else if(root->data==data)
    {
        return true;
    }
    else if(data<=root->data)
    {
        return Search(root->left,data);
    }
    else
    {
        return Search(root->right,data);
    }
}
int findmin(bstnode* root)
{
    if(root==NULL)
    {
        cout<<"Error: Empty"<<endl;
        return -1;
    }
    else if(root->left==NULL)
    {
        return root->data;
    }
    return findmin(root->left);
}

int findmax(bstnode* root)
{
    if(root==NULL)
    {
        return -1;
    }
    else if(root->right==NULL)
    {
        return root->data;
    }
    return findmax(root->right);
}

int main(void)
{
    struct bstnode* root=NULL;
    root=Insert(root,15);
    root=Insert(root,20);
    root=Insert(root,25);
    root=Insert(root,12);
    root=Insert(root,18);
    root=Insert(root,14);
    root=Insert(root,8);

    int data;
    cout<<"Enter Required Number: "<<endl;
    cin>>data;
    if(Search(root,data)==true)
    {
        cout<<"Found"<<endl;
    }
    else
    {
        cout<<"Not Found"<<endl;
    }
    cout<<"Minimum Number Is: "<<endl;
    cout<<findmin(root)<<endl;
    cout<<"Maximum number Is: "<<endl;
    cout<<findmax(root)<<endl;
    return 0;
}
