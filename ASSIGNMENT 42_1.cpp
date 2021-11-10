// 1. Write generic program which accept one value and one number from user. Print
// that value that number of times on screen.
// Input : M 7
// Output : M M M M M M M
// Input : 11 3
// Output : 11 11 11
#include<iostream>
using namespace std;
template <class T>
void Display(T Value1,int iValue2)
{
	int i = 0;
	for (i = 1;i<=iValue2;i++)
	{
		cout<<Value1<<"\t";
	}
}

int main()
{
	char Value1;
	int iValue2 = 0;
	
	cout<<"Enter first Value\n";
	cin>>Value1;
	
	cout<<"Enter Second Value\n";
	cin>>iValue2;
	
	Display(Value1,iValue2);

	return 0;
}