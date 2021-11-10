#include<iostream>

using namespace std;

class Arithmetic
{
	public:					// Access specifier
	int iNo1,iNo2;			//Characteristics
	
	void Accept()			//Behavoiur	
	{
		cout<<"Enter first Number\n";
		cin>>iNo1;
		
		cout<<"Enter second Number\n";
		cin>>iNo2;
	}
	int Addition()			//Behavoiur
	{
		int iResult = 0;
		iResult = iNo1 + iNo2;
		return iResult;
	}
	int Substraction()			//Behavoiur
	{
		int iResult = 0;
		iResult = iNo1 - iNo2;
		return iResult;
	}
};

int main()
{
	int iRet1 = 0,iRet2;
	Arithmetic obj1;
	Arithmetic obj2;
	obj1.Accept();
	iRet1 = obj1.Addition();
	cout<<"Addition is:"<<iRet1<<"\n";
	
	obj2.Accept();
	iRet2 = obj2.Substraction();
	cout<<"Substraction is:"<<iRet2<<"\n";
	
	return 0;
}