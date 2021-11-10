// Addition of array element
#include<iostream>
using namespace std;

int Addition(int Arr[],int iSize)
{
	int i = 0,iSum = 0;
	if (Arr == NULL)
	{
		return 0;
	}
	for (i = 0;i<iSize;i++)
	{
		iSum = iSum + Arr[i];
	
	}
	return iSum;
}

int main()
{
	int iSize = 0,iRet = 0,i=0;
	int *Arr = NULL;
	cout<<"Enter number of elements:";
	cin>>iSize;
	
	Arr = new int[iSize];
	for (i = 0;i<iSize;i++)
	{
		cout<<"Enter element:"<<(i+1);
		cin>>Arr[i];
	}
	iRet = Addition(Arr,iSize);
	cout<<"Addition is:"<<iRet<<endl;
	
	return 0;
}