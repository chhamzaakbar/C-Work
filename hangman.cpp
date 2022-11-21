#include<iostream>
using namespace std;
int pos;

	char ch[9]={'@','|','<','-','-','>','/','\\'};

class Hangman
{
public:
struct node
{
	char data;
	node *next;
	
}*head=NULL,*tail=NULL;

	int size;
	Hangman()
	{
		size=0;
	}
	
	
	
void Extend_node(char dataa)
{
//	system("cls");
    size++;
	node *temp;
	temp=new node;
	temp->data=dataa;
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

void Display()
{
	node *temp;
	temp=new node;
	temp=head; cout<<"\n\n\n   ";
	for(;temp!=NULL;temp=temp->next)
	cout<<temp->data<<" ";

}
int Scaning(char E)
{
	
	node *temp;
	temp=new node;
	temp=head;pos=1;
	for(;temp!=NULL;temp=temp->next)
	{
		if(temp->data==E)
		{
			return 1;
		}
		pos++;
	}
	
	return 0;
}


void Replace_at_pos(int pos,char data)
{
	node *temp;
	temp=new node;
	temp=head;

	for(int i=1;i<pos;temp=temp->next,i++)
	{
}
	temp->data=data;	
}


};

void HANGMAN_PRINT(int FULL);


int main()
{
	int FULL=5;
	

	
	
	cout<<"        "<<ch[0]<<"\n\t"<<ch[1]<<"\n      "<<ch[2]<<ch[3]<<" "<<ch[4]<<ch[5]<<"\n       "<<ch[6]<<" "<<ch[7]<<" ";
	
	Hangman hamza;
	cout<<"Storing : ";
	string x;
	cin>>x; char X;
	for(int i=0;i<x.size();i++)
	hamza.Extend_node(x[i]);
   // cout<<"X: "<<x.size()<<"  "<<hamza.size;
	Hangman hamza_sub;
		
		for(int i=0;i<hamza.size;i++)
		{
			hamza_sub.Extend_node('_');
		}
   // cout<<"   X: "<<x.size()<<"  "<<hamza_sub.size;
	

		hamza.Display();
		hamza_sub.Display();
	    char E;
		int i=0;
		for(;FULL>=0;)
		{
			cout<<"\n\n\nEnter char_";
			cin>>E;
			if(hamza.Scaning(E)==1)
			{
				hamza_sub.Replace_at_pos(pos,E); i++;
			}else FULL--;
			hamza_sub.Display();
			HANGMAN_PRINT(FULL);
			
			if(i==hamza_sub.size)
			{
				break;
			}
		}
         
		
}


void HANGMAN_PRINT(int FULL)
{
		cout<<"\n\n";
				if(FULL==5)
			{
				cout<<"        "<<ch[0]<<"\n\t"<<ch[1]<<"\n      "<<ch[2]<<ch[3]<<" "<<ch[4]<<ch[5]<<"\n       "<<ch[6]<<" "<<ch[7]<<" ";
			}
				if(FULL==4)
			{
				cout<<"        "<<ch[0]<<"\n\t"<<ch[1]<<"\n      "<<ch[2]<<ch[3]<<" "<<ch[4]<<ch[5]<<"\n       "<<ch[6];
			}
				if(FULL==3)
			{
				cout<<"        "<<ch[0]<<"\n\t"<<ch[1]<<"\n      "<<ch[2]<<ch[3]<<" "<<ch[4]<<ch[5];
			}
				if(FULL==2)
			{
				cout<<"        "<<ch[0]<<"\n\t"<<ch[1]<<"\n      "<<ch[2]<<ch[3];
			}
				if(FULL==1)
			{
				cout<<"        "<<ch[0]<<"\n\t"<<ch[1];
			}
				if(FULL==0)
			{
				cout<<"        "<<ch[0];
			}
}
