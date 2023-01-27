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

int height_of_node(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    
    int left=height_of_node(root->left);
    int right=height_of_node(root->right);
    
    return max(left,right)+1;
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
    
    cout<<height_of_node(root);
    return 0;            
}    

OUTPUT:

4