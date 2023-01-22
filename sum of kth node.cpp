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

int sum_at_kth_node(node*root,int n)
{
    int count=0;
    int sum=0;
    
    if(root==NULL)
    {
        return -1;
    }
    
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty() )
     {
        node*node=q.front();
        q.pop();
        
        if(node!=NULL)
        {
            if(count==n)
            {
                sum=sum+(node->data);
            }
            
            if(node->left)
            {
                q.push(node->left);
            }
            
            if(node->right)
            {
                q.push(node->right);
            }
        }  
        
        else if(!q.empty())
        {
            q.push(NULL);
            count++;
        }
    }
    return sum;
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
    
    int n;
    cin>>n;
    
    cout<<sum_at_kth_node(root,n);
    return 0;            
}    
