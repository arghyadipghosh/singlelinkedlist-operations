#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
};
class list:public node
{
    node *head,*tail;
    public:
    list()
    {
        head=NULL;
        tail=NULL;
    }
    void create();
    void insert();
    void delet();
    void display();
    
};
void list::create()
{
    node* temp=new node;
    int val;
    cout<<"enter an element:";
    cin>>val;
    temp->data=val;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }
}
void list::insert()
{
    node* temp=new node;
    node *temp1=new node;
    int val,n,pos;
    cout<<"enter the element:";
    cin>>val;
    temp->data=val;
    temp->next=NULL;
    cout<<"\nINSERT AS\n1:FIRSTNODE\n2:LASTNODE\n3:IN BETWEEN FIRST&LAST NODES";
    cout<<"\nEnter Your Choice:";
    cin>>n;
    switch(n)
    {
        case 1:
         {
            
            temp->next=head;
            head=temp;
            break;
         }
        case 2:
         {
             tail->next=temp;
             tail=temp;
             break;
         }
        case 3:
         {
            
             cout<<"enter the position to enter the element:";
             cin>>pos;
             temp1=head;
             for(int i=0;i<pos-1;i++)
             {
                 
				 temp1=temp1->next;
                 temp->next=temp1->next;
                 temp1->next=temp;
             }
             break;
             
             
         }
         default:
         {
             cout<<"wrong choice!!";
         }
        
        
    }
}
void list::delet()
{
    node* temp=new node;
    int n,pos;
     cout<<"\nDELETE\n1:FIRSTNODE\n2:LASTNODE\n3:IN BETWEEN FIRST&LAST NODES";
    cout<<"\nEnter Your Choice:";
    cin>>n;
    switch(n)
    {
        case 1:
          {
               if(head!=NULL)
               {
                   cout<<"element deleted is:"<<head->data;
                   temp=head;
                   head=head->next;
                   temp->next=NULL;
               }
               else
               {
                   cout<<"element cannot be deleted!!";
               }
               break;
          }
        case 2:
          {
              temp=head;
              while(temp->next!=tail)
              {
                  temp=temp->next;
                  
              }
              tail=temp;
              temp->next=NULL;
              break;
              
          }
        case 3:
          {
              cout<<"enetr the position from where u want to delete the element:";
              cin>>pos;
              temp=head;
              for(int i=0;i<pos-1;i++)
              {
                  temp=temp->next;
              }
              temp->next=temp->next->next;
              break;
          }
        default:
        {
            cout<<"wrong choice!!";
        }
    }
    
    
}
void list::display()
{
    node *temp=new node;
    temp=head;
    if(temp==NULL)
   {
       cout<<"\nlist is empty!!";
   
   }
   while(temp!=NULL)
       {
           cout<<temp->data;
           cout<<"->";
           temp=temp->next;
      }
  cout<<"NULL";
       
   
}
int main()
{
    list l;
    int ch;
    while(1)
    {
        cout<<"\n**** MENU ****";
        cout<<"\n1:CREATE\n2:INSERT\n3:DELETE\n4:DISPLAY\n5:EXIT\n";
        cout<<"\nEnter Your Choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            l.create();
            break;
        case 2:
            l.insert();
            break;
        case 3:
            l.delet();
            break;
        case 4:
            l.display();
            break;
        case 5:
            return 0;
        }
    }
    return 0;
}

