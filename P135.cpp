#include<iostream>
using namespace std;
//Input : _ _Abc_ _ _ p15_ _ _&_ _ AB_ _
// Output : 4

class StringX
{
	public:
		char ptr[30];
		void Accept()
		{
			cout<<"Enter a string\n";
			scanf("%[^'\n']s",ptr);
		}
		int WordCount()
		{
			int icnt = 0;
			char *str = ptr;
			while(*str !='\0')
			{
				if (*str ==' ')
				{
					while((*str ==' ')&&(*str !='\0'))
					{
						str++;
					}
				}
				else
				{
					icnt++;
					while((*str ==' ')&&(*str !='\0'))
					{
						str++;
					}
				}
			}
			return icnt;
		}
};


int main()
{
	int iRet = 0;
	StringX obj;
	obj.Accept();
	iRet = obj.WordCount();
	cout<<iRet;
	return 0;
}