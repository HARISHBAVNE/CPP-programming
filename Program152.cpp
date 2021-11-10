# include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node * next;
	struct node * prev;
}NODE,*PNODE;

class DoublyCL
{
private:
	PNODE Head;
	PNODE Tail;
	int iSize;
public:
	DoublyCL()
	{
		Head = NULL;
		Tail = NULL;
		iSize = 0;
	}
	void InsertFirst(int No)
	{
		PNODE newn = NULL;
		newn = new (NODE);
		newn->data = No;
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
			newn->next = Head;
			newn->prev = Tail;
			Head = newn;
			Tail->next = Head;
			iSize ++;
		}
	}
	void InsertLast(int No)
	{
		PNODE newn = NULL;
		newn = new (NODE);
		newn->data = No;
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
			Tail->next = Head;
			Head->prev = Tail;
			iSize ++;
		}	
	}
	void DeleteFirst()
	{
		if ((Head == NULL)&&(Tail == NULL))
		{
			return;
		}
		if (Head==Tail)
		{
			delete(Head);
			Head = NULL;
			Tail = NULL;
			iSize --;
		}
		else
		{
			PNODE temp = Head;
			Head = Head->next;
			Tail->next = Head;
			delete (temp);
			Tail->next->prev = Tail;
			iSize --;
		}
	}
	void DeleteLast()
	{
		if ((Head == NULL)&&(Tail == NULL))
		{
			return;
		}
		if (Head==Tail)
		{
			delete(Head);
			Head = NULL;
			Tail = NULL;
			iSize --;
		}
		else
		{
			int i = 0;
			PNODE temp = Head;
			for (i = 1;i<iSize-1;i++)
			{
				temp = temp->next;
			}
			delete (temp->next);
			Tail = temp;
			Tail->next = Head;
			Tail->next->prev = Tail;
			iSize --;
		}
	}
	
	void Display()
	{
		PNODE temp = Head;
		int i = 0;
		for (i = 1;i<=iSize;i++)
		{
			printf("|%d|\t",temp->data);
			temp = temp->next;	
		}
		cout<<"\n";
	}
	int Count()
	{
		return iSize;
	}
	void InsertAtPos(int No,int pos)
	{
		PNODE newn = NULL;
		newn = new (NODE);
		newn->data = No;
		newn->next = NULL;
		newn->prev = NULL;
		
		if ((pos < 1)||(pos >iSize+1))
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
			int i = 0;
			PNODE temp = Head;
			for (i = 1;i<pos-1;i++)
			{
				temp = temp->next;
			}
			newn->next = temp -> next;       
			temp -> next = newn;
			newn->prev = temp;
			newn->next->prev = newn;
			
			iSize ++;
		}
	}
	void DeleteAtPos(int pos)
	{	
		if ((pos < 1)||(pos >iSize))
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
			int i = 0;
			PNODE temp = Head;
			PNODE Target = NULL;
			for (i = 1;i<pos-1;i++)
			{
				temp = temp->next;
			}
			// temp->next = temp->next->next;            without Target ponter     
			// delete(temp->next->prev);
			// temp->next->prev = temp;
			Target = temp->next;
			temp->next = Target->next;
			Target->next->prev = temp;
			delete(Target);
			iSize --;
		}
	}
};

int main()
{
	DoublyCL obj;
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
				printf("Enter a Number\n");
				scanf("%d",&iValue);
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