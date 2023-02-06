#include<iostream>
using namespace std;

struct Node{
    int data;
    node*left;
    node*right;
    
    node(int value)
    {
        data=int;
        left=NULL;
        right=NULL;
    }
};

node*LCA(node*root,int n1,int n2)
{
    if(root==NULL)
    {
        return NULL;
    }
    
    if(root->data==n1||root->data==n2)
    {
        return root;
    }
    
    node*left=LCA(root->left,n1,n2);
    node*right=LCA(root->right,n1,n2);
    
    if(left!=NULL && right!=NULL)
    {
        return root;
    }
    
    if(left==NULL && right==NULL)
    {
        return NULL;
    }
    
    if(left!=NULL)
    {
        return LCA(root->left,n1,n2);
    }
    
    return LCA(root->right,n1,n2);
}

int find_dist(node*root,int k,int dist)
{
    if(root==NULL)
    {
        return -1;
    }
    
    if(root->data==k)
    {
        return dist;
    }
    
    int left= find_dist(root->left,k,dist+1);
    
    if(left!=-1)
    {
        return left;
    }
    
    return find_dist(root->right,k,dist+1)
    
}

int distbtw(node*root,int n1,int n2)
{
    node*lca=LCA(root, n1, n2);
    
    int d1=find_dist(lca,n1,0);
    int d2=find_dist(lca,n2,0);
    
    return (n1+n2);
}

int main()
{
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root-right->left=new node(6);
    root-right->right=new node(7);
    
    cout<<distbtw(root,4,5);
}