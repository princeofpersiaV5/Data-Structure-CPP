#include <iostream>
template<class DataType>
struct Node{
	DataType data;
	Node<DataType>* next;
};

template<class DataType>
class linkQueue
{
public:
	linkQueue();
	~linkQueue();
	void InQueue(DataType x);
	DataType OutQueue();
	DataType GetQueue();
	int Empty()
	{
		if (front==rear)
			return 1;
		else return 0;
	}
private:
	Node<DataType> *front,*rear;
};

template<class DataType>
linkQueue<DataType>::linkQueue()
{
	Node<DataType>* s=new Node<DataType>;
	s->next=NULL;
	front=rear=s;
}

template<class DataType>
void linkQueue<DataType>::InQueue(DataType x)
{
	Node<DataType>* s=new Node<DataType>;
	s->data=x;
	rear->next=s;
	rear=s;
}

template<class DataType>
DataType linkQueue<DataType>::OutQueue()
{
	if (rear==front) throw "downflow";
	Node<DataType>* p=front->next;
	DataType x=p->data;
	front->next=p->next;
	if(p->next==NULL) rear=front;
	delete p;
	return x;
}

template<class DataType>
DataType linkQueue<DataType>::GetQueue()
{
	return front->next->data;
}

template<class DataType>
linkQueue<DataType>::~linkQueue()
{
	while(front!=rear)
	{
		Node<DataType>* q=front;
		front=front->next;
		delete q;
	}
}
