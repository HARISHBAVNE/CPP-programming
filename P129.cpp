//Pattern printing
#include<iostream>
using namespace std;

class Pattern
{
	public:
		char str[30];
		Pattern()
		{
			cout<<"Enter a string:";
			scanf("%[^'\n']s",str);
		}
		void Display()
		{
			char *ptr = str;
			char *s = str;
			int icnt=0;
			while(*ptr !='\0')
			{
				while(*(s+icnt)!='\0')
				{
					cout<<*s<<"\t";
					s++;
				}
				cout<<"\n";
				icnt++;
				ptr++;
				s = str;
			}
		}
};


int main()
{
	Pattern obj;
	obj.Display();
	return 0;
}