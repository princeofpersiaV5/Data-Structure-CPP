#include <iostream>
//二叉链表
template<class DataType>
struct BiNode
{
	DataType data;
	BiNode<DataType>* lchild,*rchild;
};

template<class DataType>
class BiTree
{
public:
	BiTree(BiNode<DataType>* root){root=Creat(root);}
	~BiTree(){Release(root);}
	void PreOrder(){PreOrder(root);}
	void InOrder(){InOrder(root);}
	void PostOrder(){PostOrder(root);}
	void LeverOrder();
private:
	BiNode<DataType>* root;
	BiNode<DataType>* Creat(BiNode<DataType>* bt);
	void Release(BiNode<DataType>* bt);
	void PreOrder(BiNode<DataType>* bt);
	void InOrder(BiNode<DataType>* bt);
	void PostOrder(BiNode<DataType>* bt);
};

template<class DataType>
void BiTree<DataType>::PreOrder(BiNode<DataType>* bt)
{
	if(bt==NULL) return;
	else
	{
		std::cout<<bt->data;
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}

template<class DataType>
void BiTree<DataType>::InOrder(BiNode<DataType>* bt)
{
	if (bt==NULL) return;
	else
	{
		InOrder(bt->lchild);
		std::cout<<bt->data;
		InOrder(bt->rchild);
	}
}

template<class DataType>
void BiTree<DataType>::PostOrder(BiNode<DataType>* bt)
{
	if(bt==NULL) return;
	else
	{
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		std::cout<<bt->data;
	}
}

template<class DataType>
BiNode<DataType>* BiTree<DataType>::Creat(BiNode<DataType>* bt)
{
	DataType ch;
	std::cin>>ch;
	if(ch=='#') bt=NULL;
	else
	{
		bt=new BiNode<DataType>;
		bt->data=ch;
		bt->lchild=Creat(bt->lchild);
		bt->rchild=Creat(bt->rchild);
	}
	return bt;
}

template<class DataType>
void BiTree<DataType>::Release(BiNode<DataType>* bt)
{
	if(bt!=NULL)
	{
		Release(bt->lchild);
		Release(bt->rchild);
		delete bt;
	}
}
