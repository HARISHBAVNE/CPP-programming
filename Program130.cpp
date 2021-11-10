# include<iostream>
using namespace std;

class Stringx
{
public:
	char str[30];
	
	void Accept()
	{
		cout<<"Enter string\n";
		scanf("%[^'\n']s",str);
	}
	void Pattern()
	{
		char *ptr = str;
		char *s = str;
		int iCnt1 = 0,iCnt2 = 0;
		while(*ptr != '\0')
		{
			while(iCnt2 <= iCnt1)
			{
				cout<<*s<<"\t";
				s ++;
				iCnt2 ++;
			}
			iCnt2 = 0;
			s = str;
			ptr ++;
			iCnt1 ++;
			cout<<"\n";
		}
	}
	
};

int main()
{
	Stringx obj;
	obj.Accept();
	obj.Pattern();
	return 0;
}