#include<iostream>
using namespace std;
// Input : 1234
/*
4   3   2   1
3   2   1
2   1
1
 */

class Pattern
{
	public:
		int ino;
		void Accept()
		{
			cout<<"Enter number:";
			cin>>ino;
		}
		void Display()
		{
			int icnt = 0;
			int iValue=0,i = 0,j=0;
			iValue = ino;
			while(iValue > 0)
			{
				icnt++;
				iValue = iValue/10;
			}
			iValue = ino;
			for (i = 0;i<icnt;i++)
			{
				int temp=iValue;
				for (j = 0;j<(icnt-i);j++)
				{
					cout<<temp%10<<"  ";
					temp = temp/10;
				}
				cout<<"\n";
				iValue = iValue/10;
			}
		}
};


int main()
{
	Pattern obj;
	obj.Accept();
	obj.Display();
	return 0;
}