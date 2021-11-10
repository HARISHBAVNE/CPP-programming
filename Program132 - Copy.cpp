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
		int iValue = iNo,iCnt = 0,i = 0,j = 0;
		while(iValue > 0)
		{
			iCnt ++;
			iValue = iValue / 10;
		}
		iValue = iNo;
		for (i = iCnt;i >0;i--)
		{
			for(j = 0;j < i;j++)
			{
				cout<<iValue%10<<"\t";
				iValue = iValue / 10;
			}
			cout<<"\n";
			iValue = iNo;
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