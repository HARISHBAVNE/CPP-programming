// 1.Write generic program to multiply two numbers.

#include<stdio.h>
using namespace std;

template < class T>;
T Multiply(T No1,T No2)
{
	T iMult = 0;
	iMult = No1*No2;
	return iMult;
}

int main()
{
	int iNo1=0,iNo2 = 0;
	
	int iRet = 0;
	printf("Enter a first number\n");
	scanf("%d",&iNo1);
	
	printf("Enter a Second number\n");
	scanf("%d",&iNo2);
	
	iRet = Multiply(iNo1,iNo2);
	printf("Multiplication of two number is:%d",iRet);
	
	return 0;
}