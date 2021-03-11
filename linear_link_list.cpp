#include <iostream>

template<class DataType>
struct Node{
	DataType data;
	Node<DataType>*next;
};

template<class DataType>
class LinkList
{
public:
	LinkList();
	LinkList(DataType a[],int n);
	~LinkList();
	int Length();
	DataType Get(int i);
	int Locate(DataType x);
	void Insert(DataType x, int i);
	DataType Delete(int i);
	void PrintList();
private:
	Node<DataType>* first;
};

template<class DataType>
void LinkList<DataType>::PrintList()
{
	Node<DataType>* p=first->next;
	while(p!=NULL)
	{
		std::cout<<p->data;
		p=p->next;
	}
}

template<class DataType>
int LinkList<DataType>::Length()
{
	Node<DataType>* p=first->next;
	int count=0;
	while(p!=NULL)
	{
		p=p->next;
		count++;
	}
	return count;
}

template<class DataType>
DataType LinkList<DataType>::Get(int i)
{
	Node<DataType>* p=first->next;
	int count=0;
	while(p!=NULL&&count<i)
	{
		p=p->next;
		count++;
	}
	if(p==NULL) throw "位置错误";
	else return p->data;
}

template<class DataType>
int LinkList<DataType>::Locate(DataType x)
{
	Node<DataType>* p=first->next;
	int count=0;
	while(p!=NULL)
	{
		if(p->data==x) return count;
		p=p->next;
		count++;
	}

	return 0;
}

template<class DataType>
void LinkList<DataType>::Insert(DataType x,int i)
{
	Node<DataType>* p=first->next;
	int count=0;
	while(p!=NULL&&count<i-1)
	{
		p=p->next;
		count++;
	}
	if(p==NULL) throw "位置错误";
	else{
		Node<DataType>* s=new Node<DataType>;
		s->data=x;
		s->next=p->next;
		p->next=s;
	}
}

template<class DataType>
LinkList<DataType>::LinkList()
{
	first=new Node<DataType>;
	first->next=NULL;
}

template<class DataType>
LinkList<DataType>::LinkList(DataType a[],int n)
{
	first=new Node<DataType>;
	first->next=NULL;
	for (int i=0;i<n;i++)
	{
		Node<DataType>* s=new Node<DataType>;
		s->data=a[i];
		s->next=first->next;
		first->next=s;
	}
}

template<class DataType>
DataType LinkList<DataType>::Delete(int i)
{
	Node<DataType>* p=first;
	int count=0;
	while(p!=NULL&&count<i-1)
	{
		p=p->next;
		count++;
	}
	if(p==NULL||p->next==NULL){
		throw "位置错误";
	}
	else
	{
		Node<DataType>* q=p->next;
		DataType x=q->data;
		p->next=q->next;
		delete q;
		return x;
	}
}

template<class DataType>
LinkList<DataType>::~LinkList()
{
	while(first!=NULL)
	{
		Node<DataType>* q=first;
		first=first->next;
		delete q;
	}
}
