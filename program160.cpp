// Accept n number from user and perform the addition of that numbers

# include<iostream>
using namespace std;
typedef struct node
{
	int Data;
	struct node *next;
	
}NODE *PNODE;

class Queue
{
private:
	PNODE Head;
	int iSize;
public:
	Queue();
	void Display();
	int Count();
	void EnQueue(int);
	int DeQueue();
};
Queue::Queue()
{
	Head = NULL;
	iSize = 0;
}
void Queue::Display()
{
	PNODE temp = Head;
	cout<<"Elements in queue:\n";
	while(temp!=NULL)
	{
		cout<<temp->Data<<"\t";
		temp = temp->next;
	}
	cout<<"\n";
}
int Queue::Count()
{
	return iSize;
}
void Queue::EnQueue(int No)
{
	PNODE newn = newn (NODE);
	newn->Data = No;
	newn->next= NULL;
	if (iSize == 0)
	{
		newn->next = Head;
		Head = newn
		iSize ++;
	}
	else
	{
		newn->next = Head;
		Head = newn;
		iSize ++;
		
	}
}
int Queue::DeQueue()
{
	int iRet = -1;
	if (iSize == 0)
	{
		cout<<"Queue is Empty\n";
	}
	else 
	{
		PNODE temp = Head;
		for (int i = 0;i<iSize-1;i++)
		{
			temp = temp->next;
		}
		iRet = temp->next;
		delete (temp->next);
		temp->next = NULL;
	}
	return iRet;
}
int main()
{
	Queue qobj;
	int option = 1,iRet = 0,No = 0;
	while (option != 0)
	{
		cout<<"Enter your option\n";
		cout<<"1:Insert Element in Queue\n";
		cout<<"2:Remove Element from Queue\n";
		cout<<"3:Number of Element present in Queue\n";
		cout<<"4:Dispaly Elements\n";
		cout<<"0:Exit the application\n";
		
		cin>>option;
		
		switch(option)
		{
			case 1:
				cout<<"Enter a number\n";
				cin>>No;
				qobj.EnQueue(No);
				break;
			case 2:
				iRet = qobj.DeQueue();
				cout<<"Element removed whose value is:"<<iRet<<"\n";
				break;
			
			case 3:
				iRet = qobj.Count();
				cout<<"Number of elements in queue are:"<<iRet<<"\n";
				break;
				
			case 4:
				qobj.Display();
				break;
				
			case 0:
				cout<<"Thank you for using application\n";
				delete qobj;
				break;
			default:
				cout<<"Enter a valid option\n";
				break;
		}
		
	}
	
	
	return 0;
	
	
}