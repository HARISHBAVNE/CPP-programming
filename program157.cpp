// Accept n number from user and perform the addition of that numbers

# include<iostream>
using namespace std;

class Array
{
private:
	int *Arr;
	int iSize;
public:
	Array(int);
	~Array();
	void Accept();
	void Display();
	int Addition();
	
	
};
Array :: Array(int iNo)
{
	cout<<"Inside constructor\n";
	iSize = iNo;
	Arr = new int[iSize];
}
Array :: ~Array()
{
	cout<<"Inside Destructor\n";
	delete[]Arr;
}
void Array::Accept()
{
	cout<<"Enter the element\n";
	for (int i = 0;i<iSize;i++)
	{
		cin>>Arr[i];
	}
}
void Array :: Display()
{
	cout<<"Element of array are\n";
	for (int i =0;i<iSize;i++)
	{
		cout<<Arr[i]<<"\t";
	}
	cout<<"\n";
}
int Array :: Addition()
{
	int iSum = 0;
	for (int i = 0;i<iSize;i++)
	{
		iSum = iSum + Arr[i];
	}
	return iSum;
}
int main()
{
	int iNo=0,iRet = 0;
	cout<<"Enter the size of array\n";
	cin>>iNo;
	
	Array * obj = new Array(iNo);   // Call to constructor
	
	obj->Accept();
	obj->Display();
	iRet = obj->Addition();
	cout<<"Addition of all elements is:"<<iRet<<"\n";
	
	delete obj;			// call to  Destructor
	return 0;
}