#include<iostream>

using namespace std;

class Arithmetic
{
	public:					// Access specifier
	int iNo1,iNo2;			//Characteristics
	
	Arithmetic(int x,int y)
	{
		iNo1 = x;
		iNo2 = y;
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
	int iNo1=0,iNo2=0;
	cout<<"Enter first Number\n";
	cin>>iNo1;
	cout<<"Enter Second Number\n";
	cin>>iNo2;
	Arithmetic obj1(iNo1,iNo2);
	cout<<"Enter first Number\n";
	cin>>iNo1;
	cout<<"Enter Second Number\n";
	cin>>iNo2;
	Arithmetic obj2(iNo1,iNo2);
	
	iRet1 = obj1.Addition();
	cout<<"Addition is:"<<iRet1<<"\n";
	
	
	iRet2 = obj2.Substraction();
	cout<<"Substraction is:"<<iRet2<<"\n";
	
	return 0;
}