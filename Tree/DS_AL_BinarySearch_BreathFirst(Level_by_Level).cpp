#include<bits/stdc++.h>
#include<queue>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

void levelorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node*> Q;
    Q.push(root);

    while(!Q.empty())
    {
        Node* current=Q.front();      // when queue is not empty, through the front element of queue in current new node
        Q.pop();
        cout<<current->data<<" ";     //and pop and print

        if(current->left!=NULL)
        {
            Q.push(current->left);
        }
        if(current->right)
        {
            Q.push(current->right);
        }
    }
}

Node* Insert(Node* root,int data)
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
    else
    {
        root->right=Insert(root->right,data);
    }
    return root;
}


int main(void)
{
    Node* root=NULL;
    root=Insert(root,15); root=Insert(root,20);
    root=Insert(root,25); root=Insert(root,12);
    root=Insert(root,8); root=Insert(root,13);
    root=Insert(root,18);

    levelorder(root);
}
