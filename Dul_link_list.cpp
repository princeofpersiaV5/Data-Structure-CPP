#include <iostream>

template<class DataType>
struct DulNode
{
	DataType data;
	DulNode<DataType>* prior,*rear;
};

template<class DataType>
class DulStructure
{
}
