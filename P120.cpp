// Arithmaic operation
#include<iostream>
using namespace std;

class Arithmatic
{
	public:
		int iNo1,iNo2;
		
		Arithmatic(int iNo1,int iNo2)
		{
			this->iNo1 = iNo1;
			this->iNo2 = iNo2;
		}
		int Addition()
		{
			return (iNo1+iNo2);
		}
		int Substraction()
		{
			return (iNo1-iNo2);
		}
	
};

int main()
{
	int iNo1=0,iNo2=0,iRet = 0;
	
	cout<<"Enter first number:";
	cin>>iNo1;
	
	cout<<"Enter Second number:";
	cin>>iNo2;
	
	Arithmatic obj(iNo1,iNo2);
	iRet = obj.Addition();
	cout<<"Addition is:"<<iRet<<"\n";
	
	iRet = obj.Substraction();
	cout<<"Substraction is:"<<iRet<<endl;
	
	return 0;
}