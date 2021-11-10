#include<iostream>
using namespace std;

void Swap(int *iNo1,int *iNo2)
{
	int temp = 0;
	temp = *iNo1;
	*iNo1 = *iNo2;
	*iNo2 = temp;
	
}
int main()
{
	int iValue1 = 0,iValue2 = 0;
	cout<<"Enter first number\n";
	cin>>iValue1;
	cout<<"Enter Second number\n";
	cin>>iValue2;
	Swap(&iValue1,&iValue2);
	cout<<"After swap valueis:"<<iValue1<<"\n";
	cout<<"After swap valueis:"<<iValue2<<"\n";
	
	return 0;
}