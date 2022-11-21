//1:15
#include<iostream>
#include<string>
#include <stdlib.h>
#include<time.h>
using namespace std;

int flag_pos_1=9,flag=0;

struct node
{
	int data;
	node *next;
	
}*head=NULL,*tail=NULL;

void Extend_node(int dataa)
{
	system("cls");
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
	temp=head; cout<<"\n\n\n";
	for(int i=1;temp!=NULL;temp=temp->next,i++)
	{
	cout<<"\t\t"<<temp->data;
	if(flag_pos_1!=0&&temp==head)
	cout<<"*";
	cout<<"   ";
	if(i%3==0)
	cout<<"\n";
	

    }
	
}

void Replace_at_pos(int pos,int data)
{
	node *temp;
	temp=new node;
	temp=head;

	for(int i=1;i<pos;temp=temp->next,i++)
	{
	}
    if(pos==1)
    {
    	flag_pos_1=0;
	}
	temp->data=data;
	
}

void check_winner(int winner_decision)
{
	node *temp;
	temp=new node;
	temp=head;
	
	//flag_pos_1==0&&
	if(flag_pos_1==0&&temp->data==winner_decision&&temp->next->data==winner_decision&&temp->next->next->data==winner_decision)
	{
		system("cls");
		Display();
		cout<<"\n\n\n\tPlayer "<<winner_decision+1<<"  WINS : ";
		flag=9;
	}
	if(temp->next->next->next->data==winner_decision&&temp->next->next->next->next->data==winner_decision&&temp->next->next->next->next->next->data==winner_decision)
	{
		system("cls");
		Display();
		cout<<"\n\n\n\tPlayer "<<winner_decision+1<<"  WINS : ";
		flag=9;
		
	}
	if(temp->next->next->next->next->next->next->data==winner_decision&&temp->next->next->next->next->next->next->next->data==winner_decision&&temp->next->next->next->next->next->next->next->next->data==winner_decision)
	{
		system("cls");
		Display();
		cout<<"\n\n\n\tPlayer "<<winner_decision+1<<"  WINS : ";
		flag=9;
		
	}
	///////////////////////////
	if(flag_pos_1==0&&temp->data==winner_decision&&temp->next->next->next->data==winner_decision&&temp->next->next->next->next->next->next->data==winner_decision)
	{
		system("cls");
		Display();
		cout<<"\n\n\n\tPlayer "<<winner_decision+1<<"  WINS : ";
		flag=9;
		
	}
	if(temp->next->data==winner_decision&&temp->next->next->next->next->data==winner_decision&&temp->next->next->next->next->next->next->next->data==winner_decision)
	{
		
		system("cls");
		Display();
		cout<<"\n\n\n\tPlayer "<<winner_decision+1<<"  WINS : ";
		flag=9;
	}
	if(temp->next->next->data==winner_decision&&temp->next->next->next->next->next->data==winner_decision&&temp->next->next->next->next->next->next->next->next->data==winner_decision)
	{
		
		system("cls");
		Display();
		cout<<"\n\n\n\tPlayer "<<winner_decision+1<<"  WINS : ";
		flag=9;
	}
	/////////////////////////////
	
	if(flag_pos_1==0&&temp->data==winner_decision&&temp->next->next->next->next->data==winner_decision&&temp->next->next->next->next->next->next->next->next->data==winner_decision)
	{
		
		system("cls");
		Display();
		cout<<"\n\n\n\tPlayer "<<winner_decision+1<<"  WINS : ";
		flag=9;
	}
	if(temp->next->next->data==winner_decision&&temp->next->next->next->next->data==winner_decision&&temp->next->next->next->next->next->next->data==winner_decision)
	{
		
		system("cls");
		Display();
		cout<<"\n\n\n\tPlayer "<<winner_decision+1<<"  WINS : ";
		flag=9;
	}
	//////////////////////////////
	
}





int main()
{
     for(int i=1;i<10;i++)
     Extend_node(i);
     
    
     
     srand(time(NULL));
     int player=9;
     cout<<"Select y for Toss or any key for selection of player : ";
     char ch;
     cin>>ch;
     if(ch=='y')
     {
     	for(;;)
	    {
		 player=(rand()%3);
	     if(player!=0)
	     {
	     	cout<<"\t::  Toss  ::  Player "<<player<<"  win the Toss ";
	     	break;
		 }
	}
     
     }
     else
     {
     	for(;;)
     	{
		cout<<"\nPlayer : ";
     	cin>>player;
     	
     	if(player==1||player==2)
     	break;
     	else 
     	cout<<"\n\tINVALID";
	 }
}

int pos=2;
int i=1;
     for(;i<10||flag==9;i++)
     {
     	 Display();
     	 
     	 for(;pos>0&&pos<10;)
     	 {
		
     	 cout<<"\n\nPlayer "<<player<<"  turn :  ";
     	 cin>>pos;
     	 if(pos<=0||pos>=10)
     	 {
     	 	cout<<"\n\tINVALID"; pos=2;
		  }else 
		  {
		  Replace_at_pos(pos,player-1);
		  break;
	}
 }
     	 check_winner(player-1);
     	 
     	 if(player==1)
     	 {
     	 	player=2;
		  }else if(player==2)
     	 {
     	 	player=1;
		  }
		  
		  if(flag==9) break;
	 }
     
     if( i==10)
     {   system("cls");
     Display();
     	cout<<"\n\n\t\tGAME DRAW ";
	 }
     
     
     
     
     
     
     
}
