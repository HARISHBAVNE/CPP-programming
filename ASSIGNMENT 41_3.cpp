// 3. Write generic program to accept N values from user and return addition of that
// values..

#include<stdio.h>
# include<stdlib.h>
template <class T>
T AddN(T *Arr,T iSize)
{
	T Sum = 0;
	int i = 0;
	if (Arr == NULL)
	{
		return -1;
	}
	for (i = 1;i<=iSize;i++)
	{
		Sum = Sum + Arr[i];
	}
	return Sum;
}

int main()
{
	int *Arr = NULL;
	int iSize = 0,i=0;
	int iRet = 0;
	printf("Enter a Number of Elements\n");
	scanf("%d",&iSize);
	
	Arr = (int *)malloc(iSize * sizeof(int));
	
	printf("Enter elements\n");
	for (i = 1;i<=iSize;i++)
	{
		printf("Element No%d:",i);
		scanf("%d",&Arr[i]);
	}
	for (i = 1;i<=iSize;i++)
	{
		printf("%d\t",Arr[i]);
	}
	iRet = AddN(Arr,iSize);
	printf("Addition is:%d",iRet);
	free(Arr);
	
	return 0;
}