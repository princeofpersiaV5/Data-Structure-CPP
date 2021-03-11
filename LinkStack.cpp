#include <iostream>

template<class DataType>
struct Node{
	DataType data;
	Node<DataType>* next;
};

template<class DataType>
class LinkStack
{
public:
	LinkStack(){top=NULL;}
	~LinkStack();
	void Push(DataType x);
	DataType pop();
	DataType GetTop(){if (top!=NULL) return top->data;}
	int Empty() 
	{
		if (top!=NULL)
			return 0;
		else
			return 1;
	}
private:
	Node<DataType>* top;
};

template<class DataType>
void LinkStack<DataType>::Push(DataType x)
{
	Node<DataType>* s=new Node<DataType>;
	s->data=x;
	s->next=top;
	top=s;
}

template<class DataType>
DataType LinkStack<DataType>::pop()
{
	if(top==NULL) throw "downflow";
	DataType x=top->data;
	Node<DataType>* p=top;
	top=top->next;
	delete p;
	return x;
}

template<class DataType>
LinkStack<DataType>::~LinkStack()
{
	while(top!=NULL)
	{
		Node<DataType>* q=top;
		top=top->next;
		delete q;
	}
}
