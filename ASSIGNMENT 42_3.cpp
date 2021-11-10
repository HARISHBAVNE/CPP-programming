// 3. Write generic program to accept N values and search first occurrence of any
// specific value.
// Input : 10 20 30 10 30 40 10 40 10
// Value to search : 40
// Output : 6
#include<iostream>
using namespace std;
template <class T>

int SearchFirst(T *arr,int iSize,T no)
{
	int occurrence = 0;
	for (int i = 0;i<iSize;i++)
	{
		if (arr[i]==no)
		{
			occurrence = i+1;
			break;
		}
	}
	return occurrence;
}

int main()
{
	int *arr = NULL;
    int i = 0, iSize = 0,iRet = 0;
	int ivalue=0;
    
    printf("Enter number of elements\n");
    scanf("%d",&iSize);
    
    arr = new int[iSize];
    
    printf("Enter the elements\n");
    for(i = 0; i<iSize; i++)
    {
        scanf("%d",&arr[i]);
    }
	for (i = 0;i<iSize;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("Enter value to be search\n");
	scanf("%d",&ivalue);
    iRet = SearchFirst(arr,iSize,ivalue);
    printf("First occurance is : %d\n",iRet);
    delete []arr;
    return 0;
	
}