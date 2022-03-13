#include<bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node* left;
    struct Node* right;
};

void pre_order(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }
    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);
}

void post_order(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }
    post_order(root->left);
    post_order(root->right);
    cout<<root->data<<" ";
}

Node* Insert(struct Node* root,char data)
{
    if(root==NULL)
    {
        root=new Node();
        root->data=data;
        root->left=NULL;
        root->right=NULL;
    }
    else if(data<=root->data)
    {
        root->left=Insert(root->left,data);
    }
    else
    {
        root->right=Insert(root->right,data);
    }
}



int main(void)
{
    struct Node* root=NULL;

    root=Insert(root,'M');
    root=Insert(root,'B');
    root=Insert(root,'A');
    root=Insert(root,'C');
    root=Insert(root,'W');
    root=Insert(root,'Z');

    cout<<"PreOrder: ";pre_order(root);
    cout<<endl<<endl ;
    cout<<"InOrder: ";in_order(root);
    cout<<endl<<endl;
    cout<<"PostOrder: ";post_order(root);
    cout<<endl<<endl;
    return 0;

}
