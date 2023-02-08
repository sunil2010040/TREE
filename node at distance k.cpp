#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node*left;
    node*right;
    
    node(int value)
    {
        data=value;
        left=NULL;
        right=NULL;
    }
};

void printsubtreenodes(node*root,int k)
{
    if(root==NULL ||k<0)
    {
        return ;
    }
    
    if(k==0)
    {
        cout<<root->data<<" ";
    }
    
    printsubtreenodes(root->left,k-1);
    printsubtreenodes(root->right,k-1);
}

int printnodeatk(node*root,node*target,int k)
{
    if(root==NULL)
    {
        return -1;
    }
    
    if(root==target)
    {
        printsubtreenodes(root,k);
        return 0;
    }
    
    int dl=printnodeatk(root->left,target,k);
    if(dl!=-1)
    {
        if(dl+1==k)
        {
            cout<<root->data<<" ";
        }
        
        else
        {
            printsubtreenodes(root->right,k-dl-2);
        }
        return 1+dl;
    }
    
    int dr=printnodeatk(root->right,target,k);
    if(dr!=-1)
    {
        if(dr+1==k)
        {
            cout<<root->data<<" ";
        }
        
        else
        {
            printsubtreenodes(root->left,k-dr-2);
        }
        return 1+dr;
    }
    
    return -1;
}

void inorder(node*root)
{
    if(root==NULL)
    {
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
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
    inorder(root);
    cout<<endl;
    
    printnodeatk(root,root->left,2);
}