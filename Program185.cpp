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
	int iRet = 0;
	int iNo = 0;
	cout<<"Enter number of element\n";
	cin>>iNo;
	
	Arry<int>*obj = new Arry<int>(iNo);
	
	obj->Accept();
	iRet = obj->Maximum();
	
	cout<<"Maximum number is:"<<iRet<<"\n";
	
	delete obj;
	
	return 0;
}