#include <iostream>

const int QueueSize=100;
template<class DataType>
class cirQueue
{
public:
	cirQueue(){front=rear=QueueSize-1;}
	~cirQueue(){}
	void InQueue(DataType x);
	DataType OutQueue();
	DataType GetQueue();
	int Empty()
	{
		if (front==rear)
			return 1;
		else
			return 0;
	}
private:
	DataType data[QueueSize];
	int front,rear;
};

template<class DataType>
void cirQueue<DataType>::InQueue(DataType x)
{
	if ((rear+1)%QueueSize==front) throw "overflow";   //队尾遇到队头时上溢
	rear=(rear+1)%QueueSize;   //队尾向后一位，由于是循环，所以要对总长度取模
	data[rear]=x;
}

template<class DataType>
DataType cirQueue<DataType>::OutQueue()
{
	if (rear==front) throw "downflow";   //队尾遇到对头时下溢
	front=(front+1)%QueueSize;
	return data[front];
}

template<class DataType>
DataType cirQueue<DataType>::GetQueue()
{
	if(rear==front) throw "downflow";
	int i=(front+1)%QueueSize;
	return data[i];
}
