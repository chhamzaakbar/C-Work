#include <iostream>
using namespace std;

class node {
	public:
	int data;

	node *next;
	node *prev;
}*head=NULL,*tail;

void Append_node()//   Extend Node : Add at Last
{     system("cls");
	int value;
	cout<<"\nEnter data : ";
	cin>>value;
	
	node *temp;
	temp= new node;
	temp->data=value;
     cout<<"\n\ntemp = "<<temp;
	if(head==NULL)
	{
		head=temp;
		tail=head;
		temp->prev=NULL;
		temp->next=NULL;
	}else
	{
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
		temp->next=NULL;
	}
}

void Add_at_begin()
{   int value;
	cout<<"\nEnter data : ";
	cin>>value;
	
	node *temp;
	temp= new node;
	temp->data=value;
	
	temp->prev=NULL;
	temp->next=head;
	head->prev=temp;
	head=temp;
	
}
void Add_at_pos()
{
	int p;
	cout<<"\n Enter position : ";
	cin>>p;
	
	if (p==1)
	{
		Add_at_begin();
	} else
	 {
      	node *temp;
    	temp= new node;	

	 	
     	 cout<<"\nEnter data : ";
	      cin>>temp->data;
	      	
		 node *q;
		 q=head;
		 for(int i=2;i<p;i++)
		 {
		 	q=q->next;
		 }
		 if(q==tail)
		 {
		 	q->next=temp;
		 	temp->prev=q;
		 	temp->next=NULL;
		 	tail=temp;
		 }else 
		 {
		 	temp->next=q->next;
		 	temp->next->prev=temp;
		 	q->next=temp;
		 	temp->prev=q;
		 }
		
	}
}

void Display_forward()
{      system("cls");
	 node *q;
		 q=head;
		 for(;q!=NULL;q=q->next)
		 {
		 	cout<<q->data<<" <-> ";
		 	;
		 }
		 cout<<"Null";
	
}
void Display_backward()
{        system("cls");
     	 node *q;
		 q=tail;
		 for(;q!=NULL;q=q->prev)
		 {
		 	cout<<q->data<<" <-> ";
		 	;
		 }
		 cout<<"Null";
	
}

void Update_node_value()
{      
   int value;
	cout<<"\n Enter data(which you want to edit) : ";
	cin>>value;
	
	int t=0;
	node *ptr;
	ptr=head;
	
	for(;ptr!=NULL;ptr=ptr->next)
	{
		//cout<<"good scene 1";
		if(ptr->data==value)
		{
			t=1;
         	cout<<"\nEnter new data : ";
         	cin>>ptr->data;
		}
	}
	if(t==0)
	cout<<"Invalid number or Not matching";
}

void Delete_at_position()
{
	int p;
	cout<<"\n Enter position : ";
	cin>>p;
	node *s;//,*prevo;
	s=head;
	for(int i=1;i<p;i++)
	{
		//prevo=s;
		s=s->next;
	}
	
	if(s->next==NULL)
	{
		tail=s->prev;
		tail->next=NULL;
		
		s->prev=NULL;
		delete(s);
		
	}else if (s->prev==NULL)
	{
		head=s->next;
		head->prev=NULL;
		
		s->next=NULL;
		delete(s);
	}
	else
	{
		s->next->prev=s->prev;
		s->prev->next=s->next;
		
		//prevo->next=s->next;
		//s->next->prev=prevo;
		
		delete(s);
		
	}
}
/*oid Sorting()
{
	node *S,*pre;
	S=head;
	for(;S!=NULL;S=S->next)
	{   //cout<<"hamza99";
		for(pre=head->next;pre!=NULL;pre=pre->next)
		{ //  cout<<"\nhamza0";
			if(pre->data<pre->prev->data)
			{  // cout<<"\nhamza";
				int temp=pre->data;
				pre->data=pre->prev->data;
				pre->prev->data=temp;
				Display_forward();
				cout<<"\n\n";
			}
		}
	}
}
*/

void Sorting()
{
	node *S,*pre;
	S=head;
	for(;S!=NULL;S=S->next)
	{
		for(pre=S->next;pre!=NULL;pre=pre->next)
		{
			if(S->data>pre->data)
			{
				int temp=S->data;
				S->data=pre->data;
				pre->data=temp;
			}
		}
	}
}

int main()
{
	
	for (int x=0;x!=9;)
	{
		cout<<"\n\n\n1. Append_node : \n2. Add_at_begin : \n3. Add_at_pos : \n4. Display_forward : \n5. Display_backward : ";
		 cout<<" \n6. Update_node_value : \n7. Delete_at_position : \n8. Sorting : \n9. EXIT :    ";
		cin>>x;
		switch(x) 
		{
			case 1: { Append_node();
				break;
			}
			case 2:{    Add_at_begin();
				break;
			}
			case 3:{    Add_at_pos();
				break;
			}
			case 4:{    Display_forward();
				break;
			}
			case 5:{    Display_backward();
				break;
			}
			case 6:{    Update_node_value();
				break;
			}
			case 7:{    Delete_at_position();
				break;
			}
			case 8:{    Sorting();
				break;
			}
			case 9:{   cout<<" bye bye ";
				break;
			}
			
			default :
				cout<<"\n\nInvalid";
		}

	}
			
	return(0);
	
}
