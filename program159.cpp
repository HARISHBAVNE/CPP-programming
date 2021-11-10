// Accept n number from user and perform the addition of that numbers

# include<iostream>
using namespace std;

class Stack
{
private:
	int *Arr;
	int iSize;
	int Top;
public:
	Stack(int);
	~Stack();
	void push(int);
	int Pop();
	void Display();
	
};

Stack :: Stack(int iNo)
{
	iSize = iNo;
	Top = -1;
	Arr = new int[iSize];
}
Stack :: ~Stack()
{
	delete[]Arr;
}
void Stack::push(int iNo)
{
	if (Top == iSize-1)
	{
		cout<<"Stack is full\n";
	}
	else
	{
		Top ++;
		Arr[Top] = iNo;
	}
}
int Stack:: Pop()
{
	if (Top == -1)
	{
		cout<<"Stack is empty\n";
		return -1;
	}
	else
	{
		int iNo = Arr[Top];
		Top --;
		return iNo;
	}
}
void Stack:: Display()
{
	if (Top == -1)
	{
		cout<<"Stack is empty\n";
	}
	else
	{
		for (int i = 0;i<Top;i++)
		{
			cout<<Arr[i]<<"\t";
		}
		cout<<"\n";
	}
}
int main()
{
	int iNo = 0, iRet = 0;
    cout<<"Enter the size of array\n";
    cin>>iNo;
    
    Stack obj(iNo);
    obj.push(11);
    obj.push(21);
    obj.push(51);
    
    obj.Display();
    
    iRet = obj.Pop();
    cout<<"Poped element is : "<<iRet<<"\n";
    iRet = obj.Pop();
    cout<<"Poped element is : "<<iRet<<"\n";
    
    return 0;
	
}