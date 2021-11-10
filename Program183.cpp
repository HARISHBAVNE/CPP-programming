# include<iostream>
using namespace std;
template<class T>
T Maximum(T Arr[],int iSize)
{
	T iMax = Arr[0];
	for (int i=1;i<iSize;i++)
	{
		if (Arr[i]>iMax)
		{
			iMax = Arr[i];
		}
	}
	return iMax;
}


int main()
{
	int *arr = NULL;
	int iSize = 0,iRet = 0;
	cout<<"Enter number of elements\n";
	cin>>iSize;
	arr = new int[iSize];
	
	cout<<"Enter the values\n";
	for (int i = 0;i<iSize;i++)
	{
		cin>>arr[i];
	}
	iRet = Maximum(arr,iSize);
	cout<<"Maximum number is:"<<iRet<<"\n";
	delete []arr;
	return 0;
}