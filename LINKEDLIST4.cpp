
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
	struct node *prev;
};

///////////////////////////////////////////////////
//Doubly Circular Linked List.
// Class Tempalate of Doubly Circular Linked List
//////////////////////////////////////////////////
template <class T >
class DoublyCL
{
private:
	struct node <T>*Head;
	struct node <T>*Tail;
	int iSize;
	
public:
	/////////////////////////////////////
	//Function declartion
	////////////////////////////////////
	DoublyCL();
	~DoublyCL();
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
//Doubly Circular Linked List.
//Constructor
////////////////////////////////////////////////
template <class T >
DoublyCL < T > :: DoublyCL()
{
	Head = NULL;
	Tail = NULL;
	iSize = 0;
}

////////////////////////////////////////////////
//Doubly Circular Linked List.
//Destructor.
////////////////////////////////////////////////
template <class T >
DoublyCL < T > :: ~DoublyCL()
{
	cout<<"Inside Destructor\n";
}


////////////////////////////////////////////////
//Doubly Circular Linked List.
//Function for Insert Element at first.
////////////////////////////////////////////////
template <class T >
void DoublyCL <T> :: InsertFirst(T No)
{
	struct node <T> *temp = Head;
	struct node <T> *newn = NULL;
	newn = new struct node <T>;
	newn->data = No;
	newn->next = NULL;
	newn->prev = NULL;
	
	if (iSize == 0)
	{
		Head = newn;
		Tail = newn;
		Tail->next = Head;
		Head->prev = Tail;
		iSize ++;
	}
	else
	{
		newn->next = Head;
		Head = newn;
		Tail->next = Head;
		Head->prev = Tail;
		iSize ++;
	}
}

////////////////////////////////////////////////
//Doubly Circular Linked List.
//Function for Insert Element at Last.
////////////////////////////////////////////////
template <class T >
void DoublyCL < T > ::InsertLast(T No)
{
	struct node <T> *newn = NULL;
	newn = new struct node <T>;
	newn->data = No;
	newn->next = NULL;
	newn->prev = NULL;
	
	if (iSize == 0)
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

////////////////////////////////////////////////
//Doubly Circular Linked List.
//Function for Insert Element at given position.
////////////////////////////////////////////////
template <class T>
void DoublyCL < T >::InsertAtPosition(T No,int Pos)
{
	struct node < T > *newn = NULL;
	newn = new (struct node < T > );
	newn->data = No;
	newn->next = NULL;
	newn->prev = NULL;
	
	struct node < T > *temp = Head;
	if ((Pos <0 ) ||(Pos > iSize+1))
	{
		cout<<"Invalid position\n";
		return;
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
		for (int i = 1;i< Pos-1;i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		newn->next->prev = newn;
		temp->next = newn;
		newn->prev = temp;
		iSize ++;
	}
	
}

////////////////////////////////////////////////
//Doubly Circular Linked List.
//Function for Delete Element at first.
////////////////////////////////////////////////
template <class T >
void DoublyCL < T > :: DeleteFirst()
{
	struct node <T> *temp = Head;
	if (iSize == 0)
	{
		cout<<"Linked list is empty\n";
		return;
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
		Tail->next = Head;
		Head->prev = Tail;
		delete(temp);
		iSize --;
	}
	
}

////////////////////////////////////////////////
//Doubly Circular Linked List.
//Function for Delete Element at Last.
////////////////////////////////////////////////
template <class T >
void DoublyCL < T > :: DeleteLast()
{
	struct node <T> *temp = Head;
	if (iSize == 0)
	{
		cout<<"Linked list is empty\n";
		return;
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
		while (temp->next!=Tail)
		{
			temp = temp->next;
		}
		delete(Tail);
		Tail = temp;
		Tail->next = Head;
		Head->prev = Tail;
		iSize --;
	}
	
}

////////////////////////////////////////////////
//Doubly Circular Linked List.
//Function for Delete Element at given position.
////////////////////////////////////////////////
template <class T>
void DoublyCL < T >::DeleteAtPosition(int Pos)
{
	struct node < T > *temp = Head;
	struct node < T > *Target = Head;
	if ((Pos < 0)||(Pos > iSize))
	{
		cout<<"Invalid Position\n";
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
		for (int i = 1;i<Pos-1;i++)
		{
			temp = temp->next;
		}
		Target = temp->next;
		temp->next = Target->next;
		Target->next->prev = temp;
		delete(Target);
		iSize --;
	}
	
	
}

////////////////////////////////////////////////
//Doubly Circular Linked List.
//Function for Display Elements in Linked list.
////////////////////////////////////////////////
template <class T >
void DoublyCL<T>:: Display()
{
	struct node <T> *temp = Head;
	;
	for (int i = 1;i<=iSize;i++)
	{
		cout<<"|"<<temp->data<<"|"<<"<=>"<<"\t";
		temp = temp->next;
	}
	cout<<"\n";
	
}

////////////////////////////////////////////////////////
//Doubly Circular Linked List.
//Function for Count Number of elements in Linked list.
///////////////////////////////////////////////////////
template <class T >
int DoublyCL<T>::Count()
{
	return iSize;
}


int main()
{
	
	int iRet = 0;
	///////////////////////////////////////////
	//Doubly Circular Linked List.
	///////////////////////////////////////////
	DoublyCL <int> obj3;
	// obj3.InsertFirst(40);
	// obj3.InsertFirst(30);
	// obj3.InsertFirst(20);
	obj3.InsertFirst(10);
	
	// obj3.InsertLast(50);
	
	// obj3.DeleteFirst();
	// obj3.DeleteLast();
	
	// obj3.InsertAtPosition(70,6);
	
	obj3.DeleteAtPosition(3);
	
	obj3.Display();
	iRet = obj3.Count();
	cout<<iRet<<"\n";
	
	return 0;
}