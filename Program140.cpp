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
	void ReadData(int Size)
	{
		char Arr[20]={'\0'};
		read(fd,Arr,Size);
		printf("%s",Arr);
	}
};

int main()
{
	char str[30];
	int no;
	cout<<"Enter the file name\n";
	cin>>str;
	Filex obj(str);
	cout<<"Enter number of charachter you want to read\n";
	cin>>no;
	obj.ReadData(no);
	return 0;
}