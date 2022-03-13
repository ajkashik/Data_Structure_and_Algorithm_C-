#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

int main(void)
{
    struct Node* root=new Node(5);

    root->left=new Node(3);
    root->right=new Node(2);
    root->right->left=new Node(1);

    cout<<root->right->left->data<<endl;
}
