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

bool is_balanced(node*root,int*height)
{
    int lh=0;int rh=0;
    
    if(root==NULL)
    {
        return true;
    }
    
    if(is_balanced(root->left,&lh)==false)
    {
        return false;
    }
    
    if(is_balanced(root->right,&rh)==false)
    {
        return false;
    }
    
    *height=max(lh,rh)+1;
    
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
    
    
    int height=0;
    if(is_balanced(root,&height))
    {
        cout<<"it is balanced tree";
    }
    
    else
    {
        cout<<"it is unbalanced tree";
    }
    
    cout<<endl;
    
    if(is_balanced(root1,&height))
    {
        cout<<"it is balanced tree";
    }
    
    else
    {
        cout<<"it is unbalanced tree";
    }
}
