#include<iostream>
using namespace std;
int flag=0;
struct stack
{
	int data;
	stack *next;
} *TOPptr=NULL;

int TOP()
{
	if(TOPptr==NULL)
	{
		cout<<"\nEmpty Stack";
	}
	else return(TOPptr->data);
}

void Push(int value)
{
	stack *ptr;
	ptr=new stack;
	ptr->data=value;
	
	if(TOPptr==NULL)
	{   ptr->next=NULL;
		TOPptr=ptr;
	} else
	{
		ptr->next=TOPptr;
		TOPptr=ptr;
	}
	
}

int Pop()
{
	if(TOPptr==NULL)
	{
		cout<<"\nEmpty Stack";
		flag=1;
	}
	else{
		stack *ptr;
		ptr=TOPptr;
		int Data;
		
		Data = TOPptr->data;
		TOPptr=TOPptr->next;
		delete(ptr);
		
		return(Data);
	}
}




int main()
{
	string exp;
	cout<<"\nEnter your Expression : ";
	getline(cin,exp);
	char ch;
	int i=0;
	while(i<exp.size())
	{
		ch=exp[i];
		if(isdigit (exp[i]))
		{
			Push (exp[i]-'0');
		}else
		{
			int opt1,opt2;
			opt2=Pop();
			opt1=Pop();
			switch (exp[i])
			{
				case '+':
					{
						Push(opt1+opt2);
						break;
					}
				case '-':
					{
						Push(opt1-opt2);
						break;
					}
					case '*':
					{
						Push(opt1*opt2);
						break;
					}
					case '/':
					{
						Push(opt1/opt2);
						break;
					}
			}
		}
		
		i++;
	}
	
	cout<<"Ans = "<<Pop()<<"\n\n\n";
	
	system("pause");
}

