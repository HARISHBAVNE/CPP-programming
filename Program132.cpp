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
	void Wordcount()
	{
		int iCnt = 0;
		char *ptr = str;
		while(*ptr != '\0')
		{
			if (*ptr !=' ')
			{
				iCnt ++;
			}
			ptr ++;
		}
		printf("%d",iCnt);
	}
	
};

int main()
{
	Stringx obj;
	obj.Accept();
	obj.Wordcount();
	return 0;
}