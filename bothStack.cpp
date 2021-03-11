#include <iostream>

const int MaxSize=100;
template <class DataType>
class BothStack
{
public:
	BothStack(){top1=-1;top2=MaxSize;}
	~BothStack(){}
	void Push(int i,DataType x);
	DataType Pop(int i);
	DataType GetPop(int i);
	int Empty(int i);
private:
	DataType data[MaxSize];
	int top1,top2;
};

template<class DataType>
void BothStack<DataType>::Push(int i,DataType x)
{
	if (top1==top2-1) throw "overflow";
	if (i==1)data[++top1]=x;
	if (i==2)data[++top2]=x;
}

template<class DataType>
DataType BothStack<DataType>::Pop(int i)
{
	if (i==1)
	{
		if (top1==-1) throw "downflow";
		return data[top1--];
	}
	if (i==2)
	{
		if (top2==MaxSize) throw "downflow";
		return data[top2++];
	}
}

template<class DataType>
int BothStack<DataType>::Empty(int i)
{
	if (i==1)
	{
		if (top1==-1)
			return 1;
		else
			return 0;
	}
	if (i==2)
	{
		if(top2==MaxSize)
		{
			return 1;
		}
		else
			return 0;
	}
}

template<class DataType>
DataType BothStack<DataType>::GetPop(int i)
{
	if (i==1)
		return data[top1];
	if (i==2)
		return data[top2];
}
