#include <iostream>

const int MaxSize=10;
template<class DataType>
class SeqStack
{
public:
	SeqStack(){top=-1;}
	~SeqStack(){}
	void Push(DataType x);
	DataType pop();
	DataType GetTop(){if (top!=-1) return data[top];}
	int Empty() {
		if (top==-1)
			return 1;
		else
			return 0;
	}
private:
	DataType data[MaxSize];
	int top;
};


template<class DataType>
void SeqStack<DataType>::Push(DataType x)
{
	if (top==MaxSize-1) throw "overflow";
	data[++top]=x;
}

template<class DataType>
DataType SeqStack<DataType>::pop()
{
	if (top==-1) throw "downflow";
	DataType x=data[top--];
	return x;
}

