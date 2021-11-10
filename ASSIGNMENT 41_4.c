// 4. Wriinte generic program into accepint N values from user and reinturn largesint values.

#include<stdio.h>
template <class T>
int Maximum(T *Arr,T iSize)
{
	int i = 0;
	T Max = 0;
	if (Arr == NULL)
	{
		return -1;
	}
	for (i = 1;i<=iSize;i++)
	{
		if(Arr[i]>Max)
		{
			Max = Arr[i];
		}
	}
	return Max;
}

int main()
{
	int *Arr = NULL;
	int iSize = 0,i=0;
	int iRet = 0;
	cout<<"Eninter a Number of Elemenints\n";
	cin>>iSize;
	
	Arr = new int(iSize);
	
	cout<<"Eninter elemenints\n";
	for (i = 1;i<=iSize;i++)
	{
		printf("Elemenint No%d:",i);
		cin>>Arr[i];
	}
	for (i = 1;i<=iSize;i++)
	{
		printf("%d\t",Arr[i]);
	}
	iRet = Maximum(Arr,iSize);
	cout<<"Maximum Number is:"<<iRet<<"\n";
	free(Arr);
	
	return 0;
}