////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Project name:Various operations on Sequesnce collection using Linked List
//Functions :  InsertFirst,InsertLast,InsertAtPosition,DeleteFirst,DeleteLast,DeleteAtPosition,Display & Count
//Input: 	   int,double,char.
//Output:	   Depends on which function called.
//Description: It is used to check whthwr number is even or odd
//Date:		   26-05-2021
//Author nmae: HARISH VIJAY BAVNE
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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

//////////////////////////////////////////////////
// Class Tempalate of Singly Linear linked List.
/////////////////////////////////////////////////
template <class T >
class SinglyLL
{
private:
	struct node <T>*Head;
	int iSize;
	
public:
	/////////////////////////////////////
	//Function declartion
	////////////////////////////////////
	SinglyLL();
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
//Function for Insert Element at first.
////////////////////////////////////////////////
template <class T >
SinglyLL < T > :: SinglyLL()
{
	Head = NULL;
	iSize = 0;
}
template <class T >
void SinglyLL <T> :: InsertFirst(T No)
{
	struct node <T> *newn = NULL;
	newn = new struct node <T>;
	newn->data = No;
	newn->next = NULL;
	
	newn->next = Head;
	Head = newn;
	iSize ++;
}

////////////////////////////////////////////////
//Function for Insert Element at Last.
////////////////////////////////////////////////
template <class T >
void SinglyLL < T > ::InsertLast(T No)
{
	struct node <T> *newn = NULL;
	newn = new struct node <T>;
	newn->data = No;
	newn->next = NULL;
	struct node <T> *temp = Head;
	
	if (Head == NULL)
	{
		Head = newn;
		iSize ++;
	}
	else if (Head->next == NULL)
	{
		Head->next = newn;
		iSize ++;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
		iSize++;
	}
	
}

////////////////////////////////////////////////
//Function for Insert Element at given position.
////////////////////////////////////////////////
template <class T>
void SinglyLL < T >::InsertAtPosition(T No,int Pos)
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
//Function for Delete Element at First.
////////////////////////////////////////////////
template <class T >
void SinglyLL < T > :: DeleteFirst()
{
	struct node <T> *temp = Head;
	if (Head == NULL)
	{
		return ;
	}
	else
	{
		Head = Head->next;
		delete(temp);
		iSize --;
	}
}

////////////////////////////////////////////////
//Function for Delete Element at Last.
////////////////////////////////////////////////
template <class T >
void SinglyLL < T > :: DeleteLast()
{
	struct node <T> *temp = Head;
	if (Head == NULL)
	{
		return ;
	}
	if (Head->next == NULL)
	{
		delete(temp);
		Head = NULL;
		iSize --;
	}
	else
	{
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		delete(temp->next);
		temp->next = NULL;
		iSize --;
	}
}

////////////////////////////////////////////////
//Function for Delete Element at given position
////////////////////////////////////////////////
template <class T>
void SinglyLL < T >::DeleteAtPosition(int Pos)
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
//Function for Display Elements in Linked List.
////////////////////////////////////////////////
template <class T >
void SinglyLL<T>:: Display()
{
	struct node <T> *temp = Head;
	while(temp != NULL)
	{
		cout<<temp->data<<"\t";
		temp = temp->next;
	}
	cout<<"\n";
}

////////////////////////////////////////////////
//Function for Number of Element in Linked List.
////////////////////////////////////////////////
template <class T >
int SinglyLL<T>::Count()
{
	return iSize;
}

/////////////////////////////////////////
//  Main Satrter
////////////////////////////////////////
int main()
{
	
	int iRet = 0;
	SinglyLL <int> obj;
	obj.InsertFirst(40);
	obj.InsertFirst(30);
	obj.InsertFirst(20);
	obj.InsertFirst(10);
	
	obj.InsertLast(50);
	
	// obj.DeleteFirst();
	// obj.DeleteLast();
	
	// obj.InsertAtPosition(70,5);
	
	//obj.DeleteAtPosition(3);
	
	obj.Display();
	iRet = obj.Count();
	cout<<iRet<<"\n";
	return 0;
}