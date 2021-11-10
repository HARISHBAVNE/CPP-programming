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
			exit 0;
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
		int ret = 0;
		char *Arr=new char[Size];
		ret = read(fd,Arr,Size);
		printf("%d\n",ret);
		write(1,Arr,ret);
		
		delete []Arr;
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