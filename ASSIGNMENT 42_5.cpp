// 5. Write generic program to accept N values and reverse the contents.
// Input : 10 20 30 10 30 40 10 40 10
// Output : 10 40 10 40 30 10 30 20 10
#include<iostream>
using namespace std;
template <class T>

void Reverse(T *arr, int ilength)
{
	T *temp = arr;
	for (int i = 0;i<ilength;i++)
	{
		temp ++;
	}
	temp --;
	for (int i = 0;i<ilength;i++)
	{
		cout<<*temp<<"\t";
		temp --;	
	}
	
}

int main()
{
	float *arr = NULL;
    int i = 0, iSize = 0;
    
    printf("Enter number of elements\n");
    scanf("%d",&iSize);
    
    arr = new float[iSize];
    
    printf("Enter the elements\n");
    for(i = 0; i<iSize; i++)
    {
        scanf("%f",&arr[i]);
    }
	for (i = 0;i<iSize;i++)
	{
		printf("%f\t",arr[i]);
	}
	printf("\n");
    Reverse(arr,iSize);
    delete []arr;
    return 0;
	
}