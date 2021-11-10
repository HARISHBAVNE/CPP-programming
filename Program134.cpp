#include<iostream>
using namespace std;
//Input : _ _Abc_ _ _ p15_ _ _&_ _ AB_ _
// Output : _ _cbA_ _ _ 51p_ _ _& _ _BA_ _
// In place word reverse without using any other memory

class StringX
{
public:
    char str[30];
    void Accept()
    {
        cout<<"Enter String\n";
        scanf("%[^'\n']s",str);
    }
    void WordReverse()
    {
		char *ptr = str;
		while (*ptr != '\0')
		{
			if (*ptr == ' ')
			{
				ptr ++;
			}
			else
			{
				char *start,*end;
				start = ptr;
				end = ptr;
				while(*end != '\0')
				{
					end++;
				}
				end--;
				while(start < end)
				{
					char temp;
					temp = *start;
					*start = *end;
					*end = temp;
					start++;
					end--;
				}
				
			}
		}
    }
};
int main()
{
    int ret = 0;
    StringX obj;
    obj.Accept();
    obj.WordReverse();
    cout<<obj.str;
    return 0;
}
