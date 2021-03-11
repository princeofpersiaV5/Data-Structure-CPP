#include <iostream>
#include <fstream>

int main()
{
	using namespace std;

	char mobilePhone[50];
	int year;
	double a_price;
	double b_price;

	std::ofstream outFile;
	outFile.open("carinfo.txt");

	std::cout<<"Enter a the make and model of mobile"<<std::endl;
	cin.getline(mobilePhone,50);
	cout<<"Enter the year"<<endl;
	cin>>year;
	
}
