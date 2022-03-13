#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

Node* Find(struct Node* root,int data)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(root->data==data)
    {
        return root;
    }

    else if(data<=root->data)
    {
        return Find(root->left,data);
    }
    else{
        return Find(root->right,data);
    }
}

Node* Findmin(struct Node* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    while(root!=NULL)
    {
        root=root->left;
    }
    return root;
}

Node* getsuccessor(struct Node* root,int data)
{
    struct Node* current=Find(root,data);

    if(current==NULL)
    {
        return NULL;
    }
    if(current->right!=NULL)
    {
        return Findmin(current->right);
    }
    else{
        struct Node* successor =NULL;
        struct Node* ancestor=root;

        while(ancestor!=current)
        {
            if(current->data<ancestor->data)
            {
                successor=ancestor;
                ancestor=ancestor->left;
            }
            else{
                ancestor=ancestor->right;
            }
        }
        return successor;
    }
}

void Inorder(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

Node* Insert(struct Node* root,int data)
{
    if(root==NULL)
    {
        root=new Node();
        root->data=data;
        root->left=NULL;
        root->right=NULL;
    }
    else if(data<root->data)
    {
        root->left=Insert(root->left,data);
    }
    else{
        root->right=Insert(root->right,data);
    }
    return root;
}


int main(void)
{
    Node* root=NULL;
    root=Insert(root,15);root=Insert(root,25);
    root=Insert(root,20);root=Insert(root,12);
    root=Insert(root,8);root=Insert(root,6);

    Inorder(root);
    cout<<endl;

    struct Node* successor=getsuccessor(root,6);

    if(successor==NULL)
    {
        cout<<"No Successor"<<endl;
    }
    else{
        cout<<"Successor: "<<successor->data<<endl;
    }
    return 0;
}
