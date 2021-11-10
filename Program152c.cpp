#include<iostream>
using namespace std;

typedef struct node
{
	int Data;
	struct node * next;
	struct node * prev;
}NODE, *PNODE;

class DoublyCl
{
	
private:
	PNODE Head;
	PNODE Tail;
	int iSize;
public:
	DoublyCl()
	{
		Head = NULL;
		Tail = NULL;
		iSize = 0;
	}
	void InsertFirst(int);
	void InsertLast(int);
	void InsertAtPos(int,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPosition(int);
	void Display();
	int Count();

};
void DoublyCl::InsertFirst(int No)
{
	PNODE newn = NULL;
	newn = new (NODE);
	newn->Data = No;
	newn->next = NULL;
	newn->prev = NULL;
	
	if ((Head == NULL) && (Tail == NULL))
	{
		Head = newn;
		Tail = newn;
	}
	else
	{
		newn->next = Head;
		Head->prev = newn;
		Head = newn;
	}
	Tail->next = Head;
	Head->prev = Tail;
	iSize ++;
}
void DoublyCl::InsertLast(int No)
{
	PNODE newn = NULL;
	newn = new (NODE);
	newn->Data = No;
	newn->next = NULL;
	newn->prev = NULL;
	
	if ((Head == NULL) && (Tail == NULL))
	{
		Head = newn;
		Tail = newn;
		iSize ++;
	}
	else
	{
		Tail->next = newn;
		newn->prev = Tail;
		Tail = newn;
	}
	Tail->next = Head;
	Head->prev = Tail;
	iSize ++;
}
void DoublyCl::InsertAtPos(int No,int pos)
{
	if ((pos <1)||(pos>iSize+1))
	{
		return;
	}
	if (pos == 1)
	{
		InsertFirst(No);
	}
	else if (pos == iSize+1)
	{
		InsertLast(No);
	}
	else
	{
		PNODE temp = Head;
		int i = 0;
		for (i = 1;i<pos-1;i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next->prev = newn;
		temp->next = newn;
		newn->prev = temp;
		iSize ++;
	}
}
void DoublyCl::DeleteFirst()
{
	if (iSize ==0)
	{
		return;
	}
	if (iSize == 1)
	{
		delete Head;
		Head = NULL;
		Tail = NULL;
		iSize = 0;
	}
	else
	{
		Head = Head->next;
		delete (Tail->next);
		Tail->next = Head;
		Head->prev = Tail;
		// PNODE temp = Head;
		// Head = temp->next;
		// Head->prev = Tail;
		// Tail->next = Head;
		// delete(temp)
		iSize --;
	}
}
void DoublyCl::DeleteLast()
{
	if (iSize ==0)
	{
		return;
	}
	if (iSize == 1)
	{
		delete Head;
		Head = NULL;
		Tail = NULL;
		iSize = 0;
	}
	else
	{
		Tail = Tail->prev;
		delete(Head->prev);
		Tail->next = Head;
		Head->prev = Tail;
		iSize --;
	}
}
void DoublyCl::DeleteAtPosition(int pos)
{
	if ((pos <1)||(pos>iSize))
	{
		return;
	}
	if (pos == 1)
	{
		DeleteFirst();
	}
	else if (pos == iSize)
	{
		DeleteLast();
	}
	else
	{
		PNODE temp = Head;
		int i = 0;
		for (i = 1;i<pos-1;i++)
		{
			temp = temp->next;
		}
		temp->next = temp->next->next;
		delete(temp->next->prev);
		temp->next->prev = temp;
		iSize --;
	}
}
	
}
void DoublyCl::Display()
{
	PNODE temp = Head;
	int i = 0;
	for(i = 1;i<=iSize;i++)
	{
		cout<<temp->Data<<"\t";
		temp = temp->next;
	}
	cout<<"\n";
}
int DoublyCl::Count()
{
	return iSize;
}

int main()
{
	int iChoice = 1,iRet = 0,ipos = 0,iNo = 0;
	DoublyCl obj;
	
	while (iChoice != 0)
	{
		cout<<"Enter your choice\n";
		cout<<"1:Insert first\n";
		cout<<"2:Insert Last\n";
		cout<<"3:Insert at position\n";
		cout<<"4:Delete first\n";
		cout<<"5:Delete Last\n";
		cout<<"6:Delete at Position\n";
		cout<<"7:Display content\n";
		cout<<"8:Cont number of elements\n";
		cout<<"0:Exit application\n";
		cin>>iChoice;
		
		switch(iChoice)
		{
			case 1:
				cout<<"Enter a number\n";
				cin>>iNo;
				InsertFirst(iNo);
				break;
			case 2:
				cout<<"Enter a number\n";
				cin>>iNo;
				InsertLast(iNo);
				break;
				
			case 3:
				cout<<"Enter a number\n";
				cin>>iNo;
				cout<<"Enter a position\n";
				cin>>ipos;
				InsertAtPos(iNo,ipos);
				break;
			case 4:
				DeleteFirst();
				break;
			case 5:
				DeleteLast();
				break;
			case 6:
				cout<<"Enter a position\n";
				cin>>ipos;
				DeleteAtPosition(ipos);
				break;
			case 7:
				Display();
				break;
			case 8:
				iRet = Count();
				cout<<"Number of Nodes are:"<<iRet<<"\n";
				break;
			case 0:
				cout<<"Thank you for using the application\n";
				break;
			default:
				cout<<"Please enter a valid option\n";
				break;
		}
		
	}
	return 0;
}
