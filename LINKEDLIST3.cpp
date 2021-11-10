
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
// Class Tempalate of Singly Circular Linked List
//////////////////////////////////////////////////
template <class T >
class DoublyLL
{
private:
	struct node <T>*Head;
	struct node <T>*Tail;
	int iSize;
	
public:
	/////////////////////////////////////
	//Function declartion
	////////////////////////////////////
	DoublyLL();
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
DoublyLL < T > :: DoublyLL()
{
	Head = NULL;
	Tail = NULL;
	iSize = 0;
}

////////////////////////////////////////////////
//Function for Insert Element at first.
////////////////////////////////////////////////
template <class T >
void DoublyLL <T> :: InsertFirst(T No)
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
		iSize ++;
	}
	else
	{
		newn->next = Head;
		Head = newn;
		iSize ++;
	}
}

////////////////////////////////////////////////
//Function for Insert Element at Last.
////////////////////////////////////////////////
template <class T >
void DoublyLL < T > ::InsertLast(T No)
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
		iSize ++;
	}
	
}

////////////////////////////////////////////////
//Function for Insert Element at given position.
////////////////////////////////////////////////
template <class T>
void DoublyLL < T >::InsertAtPosition(T No,int Pos)
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
//Function for Delete Element at first.
////////////////////////////////////////////////
template <class T >
void DoublyLL < T > :: DeleteFirst()
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
		// Head = temp->next;
		// temp->next->prev = NULL;
		// delete(temp);
		Head = Head->next;
		delete(Head->next->prev);
		
		iSize --;
	}
	
}

////////////////////////////////////////////////
//Function for Delete Element at Last.
////////////////////////////////////////////////
template <class T >
void DoublyLL < T > :: DeleteLast()
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
		for (int i = 1;i<iSize;i++)
		{
			temp = temp->next;
		}
		delete(temp->next);
		temp->next = NULL;
		iSize --;
	}
	
}

////////////////////////////////////////////////
//Function for Delete Element at given position.
////////////////////////////////////////////////
template <class T>
void DoublyLL < T >::DeleteAtPosition(int Pos)
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
//Function for Display Elements in Linked list.
////////////////////////////////////////////////
template <class T >
void DoublyLL<T>:: Display()
{
	struct node <T> *temp = Head;
	cout<<"NULL<=>";
	for (int i = 1;i<=iSize;i++)
	{
		cout<<"|"<<temp->data<<"|"<<"<=>"<<"\t";
		temp = temp->next;
	}
	cout<<"NULL\n";
	
}

////////////////////////////////////////////////////////
//Function for Count Number of elements in Linked list.
///////////////////////////////////////////////////////
template <class T >
int DoublyLL<T>::Count()
{
	return iSize;
}


int main()
{
	
	int iRet = 0;
	DoublyLL <int> obj3;
	obj3.InsertFirst(40);
	obj3.InsertFirst(30);
	obj3.InsertFirst(20);
	obj3.InsertFirst(10);
	
	// obj3.InsertLast(50);
	
	// obj3.DeleteFirst();
	// obj3.DeleteLast();
	
	// obj3.InsertAtPosition(70,6);
	
	// obj3.DeleteAtPosition(5);
	
	obj3.Display();
	iRet = obj3.Count();
	cout<<iRet<<"\n";
	return 0;
}