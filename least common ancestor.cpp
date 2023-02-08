#include<iostream>
#include<vector>
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

bool getpath(node*root,int key,vector<int>&path)
{
    if(root==NULL)
    {
        return false;
    }
    
    path.push_back(root->data);
    if(root->data==key)
    {
        return true;
    }
    
    if(getpath(root->left,key,path) || getpath(root->right,key,path))
    {
        return true;
    }
    
    path.pop_back();
    return false;
}

int LCA(node*root,int n1,int n2)
{
    vector<int> path1,path2;
    
    if(!getpath(root,n1,path1) || !getpath(root,n2,path2))
    {
        return -1;
    }
    
    int pc;
    for(int pc=0;pc<path1.size()&&path2.size();pc++)
    {
        if(path1[pc]!=path2[pc])
        {
            break;
        }
    }
    return path1[pc-1];
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
    
    int n1=7,n2=6;
    int lca=LCA(root,n1,n2);
    
    if(lca==-1)
    {
        cout<<"LCA doesn't exist"<<endl;
    }
    
    else
    {
        cout<<"LCA:"<<lca<<endl;
    }
    
    return 0;
}