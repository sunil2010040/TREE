#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node*left;
    struct node*right;
    
    node(int value)
    {
        data =value;
        left=NULL;
        right=NULL;
    }
};

int height(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    
    return max(lh,rh)+1;
}

bool is_balanced(node*root)
{
    if(root==NULL)
    {
        return true;
    }
    
    if(is_balanced(root->left)==false)
    {
        return false;
    }
    
    if(is_balanced(root->right)==false)
    {
        return false;
    }
    
    int lh=height(root->left);
    int rh=height(root->right);
    
    if(abs(lh-rh)<=1)
    {
        return true;
    }
    
    else
    {
        return false;
    }
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
  
    node*root1=new node(1);
    root1->left=new node(2);
    root1->left->left=new node(4);
    
    
    
    if(is_balanced(root))
    {
        cout<<"it is balanced tree";
    }
    
    else
    {
        cout<<"it is unbalanced tree";
    }
    
    cout<<endl;
    
    if(is_balanced(root1))
    {
        cout<<"it is balanced tree";
    }
    
    else
    {
        cout<<"it is unbalanced tree";
    }
}

