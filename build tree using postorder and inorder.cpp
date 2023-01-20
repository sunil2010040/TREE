#include <iostream>
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

node*buildtree(int postorder[],int inorder[],int start,int end)
{
    static int index=4;                                                    //index declared as zero
    
    if(start>end)
    {
        return NULL;
    }
    
    int current=postorder[index];                                    //take position one by one from preorder
    index--;
    
    node*none=new node(current);                                    //creation of root node from that new node
    
    if(start==end)
    {
        return none;
    }
    
    int position=search(inorder,start,end,current); 
    none->right=buildtree(postorder,inorder,position+1,end);               //position of element is given by search function
    none->left=buildtree(postorder,inorder,start,position-1);       //again call buildtree function from start to pos-1    
            //again call buildtree function from start to pos+1    
    
    return none;
}

void inorderprint(node*root)
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
    int postorder[]={1,2,3,4,5};                                     //declaring preorder in an array
    int inorder[]={4,2,1,5,3};                                      //declaring inorder in an array
    
    node*root=buildtree(preorder,inorder,0,4);                      //calling of build tree function
    inorderprint(root);

    return 0;            
}  