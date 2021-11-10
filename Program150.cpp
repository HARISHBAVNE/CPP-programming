using namespace std;

#include<iostream>
typedef struct node
{
	int Data;
	struct node * next;
}NODE,*PNODE;

class SinglyLL
{
private:
	PNODE Head;
	int iSize;

public:
	SinglyLL()					// Default constructor
	{
		Head = NULL;
		iSize = 0;
	}
	int Count()
	{
		return iSize;
	}
	void Display()
	{
		PNODE temp = Head;
		while(temp != NULL)
		{
			cout<<temp->Data<<"\t";
			temp = temp->next;
		}
		cout<<"\n";
	}
	
	void InsertFirst(int iValue)
	{
		PNODE newn = NULL;
		newn = new NODE;
		newn->Data = iValue;
		newn->next = NULL;
		if (Head == NULL)			//LL is empty
		{
			Head = newn;
		}
		else
		{
			newn->next = Head;
			Head = newn;
		}
		iSize ++;
	}
	void InsertLast(int iValue)
	{
		PNODE newn = NULL;
		PNODE temp = Head;
		newn = new NODE;
		newn->Data = iValue;
		newn->next = NULL;
		if (Head == NULL)			//LL is empty
		{
			Head = newn;
		}
		else
		{
			while(temp->next!=NULL)
			{
				temp = temp->next;
			}
			temp->next = newn;
		}
		iSize ++;
	}
	void DeleteFirst()
	{
		if (Head == NULL)
		{
			return;
		}
		else
		{
			PNODE temp = Head;
			Head = Head->next;
			delete temp;
			iSize --;
		}
	}
	void DeleteLast()
	{
		if (Head == NULL)
		{
			return;
		}
		else if (Head->next == NULL)
		{
			delete Head;
			Head = NULL;
			iSize --;
		}
		else
		{
			PNODE temp = Head;
			while(temp->next->next != NULL)
			{
				temp = temp->next;
			}
			delete(temp->next);
			temp->next = NULL;
			iSize --;
		}
	}
	
	
};

int main()
{
	int iCoice = 1;
	SinglyLL obj1;
	int iNo=0;
	
	while(iCoice !=0)
	{
		printf("\n*********************************\n");
		cout<<"Enter your choice:"<<"\n";
		cout<<"1:Insert at first position"<<"\n";
		cout<<"2:Insert at last position"<<"\n";
		cout<<"3:Insert at given Position"<<"\n";
		cout<<"4:Delete at first position"<<"\n";
		cout<<"5:Delete at last position"<<"\n";
		cout<<"6:Delete at given position"<<"\n";
		cout<<"7:Display the contents"<<"\n";
		cout<<"8:Count the number of nodes"<<"\n";
		cout<<"0:Exit the application"<<"\n";
		scanf("%d",&iCoice);
		printf("\n*********************************\n");
		switch(iCoice)
		{
			case 1:
				cout<<"Enter a Number\n";
				scanf(" %d",&iNo);
				obj1.InsertFirst(iNo);
				break;
				
			case 2:
				cout<<"Enter a Number\n";
				cin>>iNo;
				obj1.InsertLast(iNo);
				break;
				
			case 3:
				break;
			
			case 4:
				obj1.DeleteFirst();
				break;
			case 5:
				obj1.DeleteLast();
				break;	
			case 6:
				break;

			case 7:
				cout<<"Display contents\n";
				obj1.Display();
				break;
			case 8:
				iNo = obj1.Count();
				cout<<"Number of elements are:"<<iNo<<"\n";
				break;
			case 0:
				cout<<"Thank you for using the application\n";
				break;
				
			default:
				cout<<"Please enter proper Option\n";
				break;
		}
		return 0;
	}
	
	return 0;
}
