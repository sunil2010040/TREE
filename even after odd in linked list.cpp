#include<iostream>
using namespace std;

class node                  		     //USER DEFINED
{
    public:
    int data;
    node*next;
    
    node(int value)         		     //TO SPECIFY DATA AND NEXT 
    {
        data=value;
        next=NULL;
    }
};

void even_after_odd(node*&head)
{
    node*odd=head;
    node*even=head->next;
    node*evenstart=even;
    while(odd->next!=NULL && even->next!=NULL)
    {
        odd->next=even->next;
        odd=odd->next;
        
        even->next=odd->next;
        even=even->next;
    }
    
    odd->next=evenstart;
    if(odd->next!=NULL)
    {
        even->next==NULL;
    }
}

void insertatend(node*&head,int val)     //TO SPECIFY WHAT FUNCTION OF LINKEDLIST WE ARE GOING TO USE
{
    node*n=new node(val);
    
    if(head==NULL)                       //IF THERE IS NO NODE PRESENT
    {
        head=n;                          //n IS ADDED AT HEAD PLACE
        return;
    }
    
    node*temp=head;                      //TO INITAILIZE TEMP FROM HEAD
    while(temp->next!=NULL)              //ITERATE TEMP TILL NULL
    {
        temp=temp->next;
    }
    temp->next=n;
}

void display(node*head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    node*head=NULL;        
    cout<<"the data added at end of linked list:"<<endl;         
    insertatend(head,1);                 //INSERTING VALUES INSIDE LINKED LIST
    insertatend(head,2);
    insertatend(head,3);
    insertatend(head,4);
    insertatend(head,5);
    insertatend(head,6);
    insertatend(head,7);
    insertatend(head,8);
    display(head);
    
    cout<<endl;

    cout<<"odd after even in linked list:"<<endl;
    even_after_odd(head);
    display(head);
}


OUTPUT:

the data added at end of linked list:
1->2->3->4->5->6->7->8->NULL

odd after even in linked list:
1->3->5->7->2->4->6->8->NULL
