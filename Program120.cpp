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
	int iRet = 0;
	Arithmetic obj;
	obj.Accept();
	iRet = obj.Addition();
	cout<<"Addition is:"<<iRet<<"\n";
	
	iRet = obj.Substraction();
	cout<<"Substraction is:"<<iRet<<"\n";
	
	return 0;
}