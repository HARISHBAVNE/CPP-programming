# include<iostream>
using namespace std;
template <class T>
class Arry
{
	
private:
	T*Arr;
	int iSize;
public:
	Arry(int no)
	{
		iSize = no;
		Arr = new T[iSize];
	}
	~Arry()
	{
		delete []Arr;
	}
	void Accept()
	{
		cout<<"Enter the values\n";
		for (int i = 0;i<iSize;i++)
		{
			cin>>Arr[i];
		}
	}
	T Maximum()
	{
		T Max = Arr[0];
		for (int i = 1;i<iSize;i++)
		{
			if (Arr[i]>Max)
			{
				Max = Arr[i];
			}
		}
		return Max;
	}
};


int main()
{
	Arry<int>obj1(5);
	int iRet = 0;
	
	obj1.Accept();
	iRet = obj1.Maximum();
	cout<<"Maximum is:"<<iRet<<"\n";
	
	Arry<double>obj2(5);
	double dRet = 0;
	
	obj2.Accept();
	dRet = obj2.Maximum();
	cout<<"Maximum is:"<<dRet<<"\n";
	
	return 0;
}