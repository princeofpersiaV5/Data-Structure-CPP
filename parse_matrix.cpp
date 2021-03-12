#include <iostream>

template<class DataType>
struct element
{
	int row,col;
	DataType item;
};   //三元组

const int MaxTerm=100;
template<class DataType>
struct parse_matrix
{
	element<DataType>  data[MaxTerm];
	int mu,nu,tu;   //行数，列数，非零元个数
};   //三元组表
