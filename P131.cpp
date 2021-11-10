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
		int iNo;
		void Accept()
		{
			cout<<"Enter a number:";
			cin>>iNo;
		}
		void Display()
		{
			int i = iNo;
			while(i>=1)
			{
				int j = 0;
				while(j<i)
				{
					cout<<(iNo-j)<<"\t";
					j++;
				}
				i--;
				cout<<"\n";
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