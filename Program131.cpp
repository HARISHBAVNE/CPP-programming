# include<iostream>
using namespace std;

class Numberx
{
public:
	int iNo;
	
	void Accept()
	{
		cout<<"Enter number\n";
		scanf("%d",&iNo);
	}
	void Pattern()
	{
		int iValue = iNo,iTemp = 0;
		while(iValue > 0)
		{
			iTemp = iValue;
			while(iTemp > 0)
			{
				cout<<iTemp %10<<"\t";
				iTemp = iTemp/10;
			}
			cout<<"\n";
			iValue = iValue/10;
		}
		
	}
};

int main()
{
	Numberx obj;
	obj.Accept();
	obj.Pattern();
	return 0;
}