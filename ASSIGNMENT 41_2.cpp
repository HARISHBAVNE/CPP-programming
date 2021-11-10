// 2. Write generic program to find largest number from three numbers.

#include<stdio.h>
template <class T>
T Max(T No1,T No2,T No3)
{
	if (No1>No2)
	{
		if(No1>No3)
		{
			return No1;
		}
		else
		{
			return No3;
		}
	}
	else if (No2>No3)
	{
		return No2;
	}
	else
	{
		return No3;
	}
	
}
int main()
{
	int iNo1=0,iNo2 = 0,iNo3;
	
	int iRet = 0;
	printf("Enter a first number\n");
	scanf("%d",&iNo1);
	
	printf("Enter a Second number\n");
	scanf("%d",&iNo2);
	
	printf("Enter a third number\n");
	scanf("%d",&iNo3);
	
	iRet = Max(iNo1,iNo2,iNo3);
	printf("Maximum number is:%d",iRet);
	
	return 0;
}