#include <iostream>
#include<queue>
using namespace std;

struct node
{
    int data;
    struct node*left;
    struct node*right;
        
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

void sum_replacement(node*root)
{
    if(root==NULL)
    {
        return ;
    }
    
    sum_replacement(root->left);
    sum_replacement(root->right);
    
    if(root->left!=NULL)
    {
        root->data=root->data+root->left->data;
    }
    
    if(root->right!=NULL)
    {
        root->data=root->data+root->right->data;
    }
}

void preorder(struct node*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
    
int main()
{
    
    node*root=new node(1);
    
    root->left=new node(2);
    root->right=new node(3);
        
    root->left->left=new node(4);
    root->left->right=new node(5);
        
    root->right->left=new node(6);
    root->right->right=new node(7);
        
    root->left->left->left=new node(8);
    root->left->left->right=new node(9);
    
    preorder(root);
    cout<<endl;
    sum_replacement(root);
    cout<<endl;
    preorder(root);
    return 0;            
}   

OUTPUT:

1 2 4 8 9 5 3 6 7 

45 28 21 8 9 5 16 6 7 