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
    bstnode* newnode=new bstnode();
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
};

struct bstnode* Insert(struct bstnode* root,int data)
{
    if(root==NULL)
    {
        root=getnode(data);
    }
    else if(data<=root->data)
    {
        root->left=Insert(root->left,data);
    }
    else{
        root->right=Insert(root->right,data);
    }
    return root;
};

bool Search(struct bstnode* root,int data)
{
    if(root==NULL)
    {
        return false;
    }
    else if(data==root->data)
    {
        return true;
    }
    else if(root->data>=data)
    {
        return Search(root->left,data);
    }
    else{
        return Search(root->right,data);
    }
}

int main(void)
{
    struct bstnode* root=NULL;
    root=Insert(root,15);
    root=Insert(root,10);
    root=Insert(root,20);
    root=Insert(root,25);
    root=Insert(root,12);
    root=Insert(root,8);

    int number;
    cout<<"Enter Number: "<<endl;
    cin>>number;
    if(Search(root,number)==true)
    {
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
}
