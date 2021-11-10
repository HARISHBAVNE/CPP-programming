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
		fd = open(Name,O_RDONLY);
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
	void ReadData()
	{
		char Arr[10];
		int ret = 0;
		
		while((ret = read(fd,Arr,10))!=0)
		{
			write(1,Arr,ret);
		}
	}
};

int main()
{
	char str[30];
	cout<<"Enter the file name\n";
	cin>>str;
	Filex obj(str);
	
	obj.ReadData();
	return 0;
}