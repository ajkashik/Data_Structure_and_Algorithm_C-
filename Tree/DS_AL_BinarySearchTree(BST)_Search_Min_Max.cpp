#include<bits/stdc++.h>
using namespace std;
struct bstnode
{
    int data;
    struct bstnode* left;
    struct bstnode* right;
};

bstnode* getnode(int data)
{
    struct bstnode* newnode=new bstnode();
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

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
    else{
        return Search(root->right,data);
    }
}

int findmin(struct bstnode* root)
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

int findmax(struct bstnode* root)
{
    if(root==NULL)
    {
        cout<<"Error"<<endl;
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
    root=Insert(root,10);
    root=Insert(root,15);
    root=Insert(root,8);
    root=Insert(root,5);
    root=Insert(root,12);

    int data;
    cout<<"Enter Number(search): "<<endl;
    cin>>data;

    if(Search(root,data)==true)
    {
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
    cout<<"Minimum Number Is: "<<findmin(root)<<endl;
    cout<<"Maximum Number Is: "<<findmax(root)<<endl;
}
