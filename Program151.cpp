# include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node * next;
}NODE,*PNODE;

class SinglyCL
{
private:
	PNODE Head;
	PNODE Tail;
	int iSize;
public:
	SinglyCL()
	{
		Head = NULL;
		Tail = NULL;
		iSize = 0;
	}
	void InsertFirst(int iNo)
	{
		PNODE newn = NULL;
		newn = new (NODE);
		newn->data = iNo;
		newn->next = NULL;
		if ((Head == NULL) && (Tail == NULL))
		{
			Head = newn;
			Tail = newn;	
		}
		else
		{
			newn->next = Head;
			Head = newn;
		}
		iSize ++;
		Tail->next = Head;
	}

	void InsertLast(int iNo)
	{
		PNODE newn = NULL;
		newn = new (NODE);
		newn->data = iNo;
		newn->next = NULL;
		if ((Head == NULL) && (Tail == NULL))
		{
			Head = newn;
			Tail = newn;
		}
		else
		{
			Tail->next = newn;
			Tail = newn;
			
		}
		iSize ++;
		Tail->next = Head;
	}
	int Count()
	{
		return iSize;
	}
	void Display()
	{
		int i = 0;
		PNODE temp = Head;
		for (i = 1;i<=iSize;i++)
		{
			cout<<temp->data<<"\t";
			temp = temp->next;
		}
		cout<<"\n";
	}
	void DeleteFirst()
	{
		if (iSize == 0)
		{
			return;
		}
		else if (iSize == 1)
		{
			delete(Head);
			Head = NULL;
			Tail = NULL;
			iSize --;
		}
		else
		{
			Head = Head->next;
			delete(Tail->next);
			Tail->next = Head;
			iSize --;
		}
	}
	void DeleteLast()
	{
		if (iSize == 0)
		{
			return;
		}
		else if (iSize == 1)
		{
			delete(Head);
			Head = NULL;
			Tail = NULL;
			iSize --;
		}
		else
		{
			PNODE temp = Head;
			int i = 0;
			for (i = 1;i<iSize-1;i++)
			{
				temp = temp->next;
			}
			delete(temp->next);
			Tail = temp;
			Tail->next = Head;
			iSize --;
		}
	}
	void InsertAtPos(int No,int pos)
	{
		PNODE newn = NULL;
		newn = new (NODE);
		newn->data = No;
		newn->next = NULL;
		
		if ((pos < 1)||(pos > iSize+1))
		{
			return;
		}
		if (pos == 1)
		{
			InsertFirst(No);
			iSize ++;
		}
		else if (pos == iSize+1)
		{
			InsertLast(No);
			iSize ++;
		}
		else
		{
			int i = 0;
			PNODE temp = Head;
			for (i = 1;i<pos-1;i++)
			{
				temp = temp->next;
			}
			newn->next = temp->next;
			temp->next = newn;
			iSize ++;
		}
		
	}
	void DeleteAtPos(int pos)
	{
		PNODE Target = NULL;
		
		if ((pos < 1)||(pos > iSize))
		{
			return;
		}
		if (pos == 1)
		{
			DeleteFirst();
			iSize --;
		}
		else if (pos == iSize)
		{
			DeleteLast();
			iSize --;
		}
		else
		{
			int i = 0;
			PNODE temp = Head;
			for (i = 1;i<pos-1;i++)
			{
				temp = temp->next;
			}
			Target = temp->next;
			temp->next = Target->next;
			delete(Target);
			iSize --;
		}
		
	}	
	
};


int main()
{
	SinglyCL obj;
	int iChoice = 1,iRet = 0,iPos = 0,iValue = 0;
	
	while(iChoice != 0)
	{
		cout<<"Enter your choice\n";
		cout<<"1:Insert First\n";
		cout<<"2:Insert Last\n";
		cout<<"3:Insert at given Position\n";
		cout<<"4:Delete First\n";
		cout<<"5:Delete Last\n";
		cout<<"6:Delete at given Position\n";
		cout<<"7:Display  the contents \n";
		cout<<"8:Count the element\n";
		cout<<"0:Exit the application\n";
		
		cin>>iChoice;
		switch (iChoice)
		{
			case 1:
				cout<<"Enter nmber\n";
				cin>>iValue;
				obj.InsertFirst(iValue);
				break;
			
			case 2:
				cout<<"Enter nmber\n";
				cin>>iValue;
				obj.InsertLast(iValue);
				 break;
			case 3:
				cout<<"Enter nmber\n";
				cin>>iValue;
				cout<<"Enter positiom\n";
				cin>>iPos;
				obj.InsertAtPos(iValue,iPos);
				break;
			case 4:
				obj.DeleteFirst();
				break;
			case 5:
				obj.DeleteLast();
				break;
			case 6:
				cout<<"Enter Position\n";
				cin>>iPos;
				obj.DeleteAtPos(iPos);
				break;
			case 7:
				obj.Display();
				break;
			case 8:
				iRet = obj.Count();
				cout<<"Element are:"<<iRet<<"\n";
				break;
				
			case 0:
				cout<<"Theank you for using application\n";
				break;
				
			default:
				cout<<"Please enter proper option\n";
				break;
		}
	}
	return 0;
}