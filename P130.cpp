//Pattern printing
#include<iostream>
using namespace std;

class Pattern
{
	public:
		char str[30];
		void Accept()
		{
			cout<<"Enter a string:";
			scanf("%[^'\n']s",str);
		}
		void Display()
		{
			char *ptr = str;
			char *s = str;
			int icnt1=0,icnt2 = 0;
			while(*ptr !='\0')
			{
				while(icnt2<=icnt1)
				{
					cout<<*s<<"\t";
					s++;
					icnt2++;
				}
				cout<<"\n";
				icnt2=0;
				icnt1++;
				ptr++;
				
				s = str;
			}
		}
};


int main()
{
	Pattern obj;
	obj.Accept();
	obj.Display();
	return 0;
}