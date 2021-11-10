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
		fd = open(Name,O_WRONLY|O_APPEND);
		if (fd == -1)
		{
			cout<<"Unable to creat file\n";
			exit (0);
		}
		else
		{
			cout<<"File succesfully created..\n";
		}
	}
	~Filex()
	{
		close(fd);
	}
	void WriteData()
	{
		char str[]=" Pune";
		write(fd,str,5);
	}
};

int main()
{
	char str[30];
	cout<<"Enter the file name\n";
	cin>>str;
	Filex obj(str);
	
	obj.WriteData();
	return 0;
}