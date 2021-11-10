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
		int iCnt = 0;
		while(*ptr != '\0')
		{
			while((*s+iCnt)!='\0')
			{
				cout<<*s<<"\t";
				s++;
			}
			s = str;
			ptr ++;
			iCnt ++;
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