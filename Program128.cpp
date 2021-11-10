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
	int Strlenx()
	{
		int iCnt = 0;
		char *ptr = str;
		while (*ptr != '\0')
		{
			ptr ++;
			iCnt ++;
		}
		return iCnt;
	}
	
};

int main()
{
	int ret = 0;
	Stringx obj;
	obj.Accept();
	ret = obj.Strlenx();
	cout<<"String length is :"<<ret<<"\n";
	return 0;
}