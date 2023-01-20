#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node*left;
    struct Node*right;
        
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
}; 

int search(int inorder[],int start,int end,int current)
{
    for(int i=start;i<=end;i++)                                     //traverse through inorder in search function 
    {
        if(inorder[i]==current)                                     //if inorder index is equal to current then return that value of position for upcoming function
        {
            return i;
        }
    }
    return -1;
}

Node*buildtree(int preorder[],int inorder[],int start,int end)
{
    static int index=0;                                                    //index declared as zero
    
    if(start>end)
    {
        return NULL;
    }
    
    int current=preorder[index];                                    //take position one by one from preorder
    index++;
    
    Node*node=new Node(current);                                    //creation of root node from that new node
    
    if(start==end)
    {
        return node;
    }
    
    int position=search(inorder,start,end,current);                //position of element is given by search function
    node->left=buildtree(preorder,inorder,start,position-1);       //again call buildtree function from start to pos-1    
    node->right=buildtree(preorder,inorder,position+1,end);        //again call buildtree function from start to pos+1    
    
    return node;
}

void inorderprint(Node*root)
{
    if(root==NULL)
    {
        return;
    }
    
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
    
    return;
}

int main()
{
    int preorder[]={1,2,3,4,5};                                     //declaring preorder in an array
    int inorder[]={4,2,1,5,3};                                      //declaring inorder in an array
    
    Node*root=buildtree(preorder,inorder,0,4);                      //calling of build tree function
    inorderprint(root);

    return 0;            
}  