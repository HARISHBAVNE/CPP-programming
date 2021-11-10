# include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<iostream>
#include<io.h>
using namespace std;

class Filex
{
public:
	int fd;
	
	Filex(char Name[])
	{
		fd = open(Name,O_WRONLY | O_CREAT);
		if (fd == -1)
		{
			cout<<"Unable to open file\n";
		}
		else
		{
			cout<<"File succesfully opend..\n";
		}
	}
	~Filex()
	{
		close(fd);
	}
};

int main()
{
	char str[30];
	cout<<"Enter the file name\n";
	cin>>str;
	Filex obj(str);
	return 0;
}