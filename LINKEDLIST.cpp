#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;
typedef struct node * PNODE;
class SinglyLL
{
private:
	PNODE Head;
	int iSize;
	
public:
	SinglyLL();
 	void InsertFirst(int);
	void Display();
	int Count();
};
SinglyLL :: SinglyLL()
{
	Head = NULL;
	iSize = 0;
}
void SinglyLL :: InsertFirst(int No)
{
	PNODE newn = NULL;
	newn = new (NODE);
	newn->data = No;
	newn->next = NULL;
	
	newn->next = Head;
	Head = newn;
	iSize ++;
}
void SinglyLL:: Display()
{
	PNODE temp = Head;
	while(temp != NULL)
	{
		cout<<temp->data<<"\t";
		temp = temp->next;
	}
	cout<<"\n";
}
int SinglyLL::Count()
{
	return iSize;
}


int main()
{
	
	SinglyLL obj;
	obj.InsertFirst(40);
	obj.InsertFirst(30);
	obj.InsertFirst(20);
	obj.InsertFirst(10);
	
	obj.Display();
	obj.Count();
	
	return 0;
}