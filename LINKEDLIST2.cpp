
////////////////////////////////////////////
// Header
////////////////////////////////////////////

#include<iostream>
using namespace std;

////////////////////////////////////////////
// Structure Tempalate.
////////////////////////////////////////////
template <class T >
struct node
{
	T data;
	struct node *next;
};

///////////////////////////////////////////////////
// Class Tempalate of Singly Circular Linked List
//////////////////////////////////////////////////
template <class T >
class SinglyCL
{
private:
	struct node <T>*Head;
	struct node <T>*Tail;
	int iSize;
	
public:
	/////////////////////////////////////
	//Function declartion
	////////////////////////////////////
	SinglyCL();
 	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPosition(T,int Pos);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPosition(int Pos);
	
	void Display();
	int Count();
};
////////////////////////////////////////////
// Functions defination.
////////////////////////////////////////////


////////////////////////////////////////////////
//Constructor
////////////////////////////////////////////////
template <class T >
SinglyCL < T > :: SinglyCL()
{
	Head = NULL;
	Tail = NULL;
	iSize = 0;
}

////////////////////////////////////////////////
//Function for Insert Element at first.
////////////////////////////////////////////////
template <class T >
void SinglyCL <T> :: InsertFirst(T No)
{
	struct node <T> *temp = Head;
	struct node <T> *newn = NULL;
	newn = new struct node <T>;
	newn->data = No;
	newn->next = NULL;
	if (Head == NULL)
	{
		Head = newn;
		Tail = newn;
		iSize ++;
	}
	else  if (Head == Tail)
	{
		newn->next = Head;
		Tail = newn->next;
		Head = newn;
		Tail->next = Head;
		iSize ++;
	}
	else
	{
		newn->next = Head;
		Head = newn;
		Tail->next = Head;
		iSize ++;
	}
	
}

////////////////////////////////////////////////
//Function for Insert Element at Last.
////////////////////////////////////////////////
template <class T >
void SinglyCL < T > ::InsertLast(T No)
{
	struct node <T> *newn = NULL;
	newn = new struct node <T>;
	newn->data = No;
	newn->next = NULL;
	struct node <T> *temp = Head;
	
	if (Head == NULL)
	{
		Head = newn;
		Tail = newn;
		iSize ++;
	}
	else if (Head == Tail)
	{
		Tail->next = newn;
		Tail = newn;
		Tail->next = Head;
		iSize ++;
	}
	else
	{
		Tail->next = newn;
		Tail = newn;
		Tail->next = Head;
		iSize++;
	}
}

////////////////////////////////////////////////
//Function for Insert Element at given position.
////////////////////////////////////////////////
template <class T>
void SinglyCL < T >::InsertAtPosition(T No,int Pos)
{
	struct node < T > *newn = NULL;
	newn = new (struct node < T > );
	newn->data = No;
	newn->next = NULL;
	
	struct node < T > *temp = Head;
	
	if ((Pos < 0) || (Pos > iSize+1))
	{
		cout<<"Invalid position\n";
		return ;
	}
	if (Pos == 1)
	{
		InsertFirst(No);
	}
	else if(Pos == iSize+1)
	{
		InsertLast(No);
	}
	else
	{
		for (int i = 1;i < (Pos-1); i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;
		iSize ++;
	}
	
	
}

////////////////////////////////////////////////
//Function for Delete Element at first.
////////////////////////////////////////////////
template <class T >
void SinglyCL < T > :: DeleteFirst()
{
	struct node <T> *temp = Head;
	if (Head == NULL)
	{
		cout<<"Linked list is empty\n";
		return ;
	}
	if (Head == Tail)
	{
		delete(Head);
		Head = NULL;
		Tail = NULL;
		iSize --;
	}
	else
	{
		Head = temp->next;
		delete(temp);
		Tail->next = Head;
		iSize --;
	}
}

////////////////////////////////////////////////
//Function for Delete Element at Last.
////////////////////////////////////////////////
template <class T >
void SinglyCL < T > :: DeleteLast()
{
	struct node <T> *temp = Head;
	if (Head == NULL)
	{
		return ;
	}
	if (Head == Tail)
	{
		delete(temp);
		Head = NULL;
		Tail = NULL;
		iSize --;
	}
	else
	{
		while(temp->next->next != Head)
		{
			temp = temp->next;
		}
		delete(temp->next);
		temp = Tail;
		Tail->next = Head;
		iSize --;
	}
}

////////////////////////////////////////////////
//Function for Delete Element at given position.
////////////////////////////////////////////////
template <class T>
void SinglyCL < T >::DeleteAtPosition(int Pos)
{
	struct node < T > *temp = Head;
	struct node < T > *Target = NULL;
	
	if ((Pos < 0) || (Pos > iSize))
	{
		cout<<"Invalid position\n";
		return ;
	}
	if (Pos == 1)
	{
		DeleteFirst();
	}
	else if (Pos == iSize)
	{
		DeleteLast();
	}
	else
	{
		for (int i = 1; i< (Pos-1);i++)
		{
			temp = temp->next;
		}
		Target = temp->next;
		temp->next = Target->next;
		delete(Target);
		iSize --;
	}
	
	
	
}

////////////////////////////////////////////////
//Function for Display Elements in Linked list.
////////////////////////////////////////////////
template <class T >
void SinglyCL<T>:: Display()
{
	struct node <T> *temp = Head;
	for (int i = 1;i<=iSize;i++)
	{
		cout<<temp->data<<"\t";
		temp = temp->next;
	}
	cout<<"\n";
	
}

////////////////////////////////////////////////////////
//Function for Count Number of elements in Linked list.
///////////////////////////////////////////////////////
template <class T >
int SinglyCL<T>::Count()
{
	return iSize;
}


int main()
{
	
	int iRet = 0;
	SinglyCL <int> obj1;
	obj1.InsertFirst(40);
	obj1.InsertFirst(30);
	obj1.InsertFirst(20);
	obj1.InsertFirst(10);
	
	obj1.InsertLast(50);
	
	obj1.DeleteFirst();
	obj1.DeleteLast();
	
	obj1.InsertAtPosition(70,5);
	
	obj1.DeleteAtPosition(7);
	
	obj1.Display();
	iRet = obj1.Count();
	cout<<iRet<<"\n";
	return 0;
}