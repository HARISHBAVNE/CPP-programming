# include<iostream>
using namespace std;
typedef struct node
{
	int data;
	struct node * next;
}NODE,*PNODE;

class Stack
{
private:
	PNODE Head;
	int iSize;
public:
	Stack();			// Constructor
	~Stack();			//Destructor
	void Push(int);		// void InsertFirst(int)
	int pop();			// void Delete First()
	int Peek();			// Just return the value 
	void Display();
	int Count();
};
Stack::Stack()     // Constructor
{
	cout<<"Inside destructor\n";
	this ->Head = NULL;
	this->iSize = 0;
}
Stack::~Stack()		//Destructor
{
	cout<<"Inside destructor";
	PNODE temp = NULL;
	while(Head!=NULL)
	{
		temp = Head;
		Head = Head->next;
		delete(temp);
	}
}
void Stack::Push(int No)
{
	PNODE newn = NULL;
	newn = new (NODE);
	newn->data = No;
	newn->next = NULL;
	
	newn->next = Head;
	Head = newn;
	iSize ++;
}

int Stack::pop()
{
	int iret = -1;
	if (iSize == 0)
	{
		cout<<"Stack is Empty\n";
	}
	else
	{
		PNODE temp = Head;
		Head = Head->next;
		iret = temp->data;
		delete(temp);
		iSize --;
	}
	
	return iret;
}
int Stack::Peek()
{
	if (iSize == 0)
	{
		return -1;
	}
	else
	{
		return Head->data;	
	}
}
void Stack::Display()
{
	while(Head!=NULL)
	{
		printf("%d\t",Head->data);
		Head = Head->next;
	}
	printf("\n");
}
int Stack::Count()
{
	return this->iSize;
}


int main()
{
	Stack *sobj = new Stack;//Stack sobj;      it implicitly calls the constructor
	int option = 1,iret = 0,iNo = 0;
	while(option != 0)
	{
		cout<<"Please select the option\n";
		cout<<"1:Push the element\n";
		cout<<"2: POP the element\n";
		cout<<"3: Display the element\n";
		cout<<"4:Count the number of element\n";
		cout<<"5: Display value of Top element\n";
		cout<<"0: Exit the application\n";
		
		cin>>option;
		
		switch(option)
		{
			case 1:
				cout<<"Enter the element to push\n";
				cin>>iNo;
				sobj->Push(iNo);
				break;
				
			case 2:
				iret = sobj->pop();
				cout<<"Popped element is:"<<iret<<"\n";
				
				break;
				
			case 3:
				cout<<"Element of stack are\n";
				sobj->Display();
				break;
				
			case 4:
				iret = sobj->Count();
				cout<<"Number of element are:"<<iret<<"\n";
				break;
				
			case 5:
				iret = sobj->Peek();
				cout<<"Value of top element is:"<<iret<<"\n";
				break;
			
			case 0:
				cout<<"Thank you for using application\n";
				delete sobj;       // It implicitly calls the destructor.
				break;
			default:
				cout<<"Please enter a valid option\n";
				break;
		}
	}
	
	return 0;
}