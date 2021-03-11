#include <iostream>

const int MaxSize=100;
template <class DataType>
class SeqList
{
public:
	SeqList(){length=0;}
	SeqList(DataType a[],int n);
	~SeqList(){}
	int Length(){return length;}
	DataType Get(int i);
	int Locate(DataType x);
	void Insert(int i,DataType x);
	DataType Delete(int i);
	void PrintList();
private:
	DataType data[MaxSize];
	int length;
};

template<class DataType>
SeqList<DataType>::SeqList(DataType a[],int n)
{
	if (n>MaxSize) throw "参数非法";
	for (int i=0;i<n;i++)
		data[i]=a[i];
	length=n;
}

template<class DataType>
DataType SeqList<DataType>::Get(int i)
{
	if(i<1&&i>length) throw "查找位置非法";
	else return data[i-1];
}

template<class DataType>
int SeqList<DataType>::Locate(DataType x)
{
	for (int i=0;i<length;i++)
		if(data[i]==x)
		{
			return i+1;
		}
	return 0;
}

template<class DataType>
void SeqList<DataType>::Insert(int i,DataType x)
{
	if(length>=MaxSize) throw "上溢";
	if(i<1||i>length+1) throw "位置出错";
	for (int j=length;j>=i;j--)
	{
		data[j]=data[j-1];
		data[i-1]=x;
		length++;
	}
}

template<class DataType>
DataType SeqList<DataType>::Delete(int i)
{
	if (length==0) throw "下逸";
	if(i<1||i>length) throw "位置出错";
	DataType x=data[i-1];
	for (int j=i;j<length;j++)
	{
		data[j-1]=data[j];
	}
	length--;
	return x;
}

template<class DataType>
void SeqList<DataType>::PrintList()
{
	for (int i=0;i<length;i++)
	{
		std::cout<<data[i];
	}
}


