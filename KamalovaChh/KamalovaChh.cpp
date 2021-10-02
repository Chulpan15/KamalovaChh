#include <iostream>
using namespace std;

struct Pipe
{
	int id;
	int diametr;
	double length;
	bool InRepair = false;
};

struct CompressionStation
{
	int id = 0;
	string name;
	int NumberOfWorkshops;
	int NumberOfWorkshopsInOperation;
	double effiency;

};

void PrintPipe(Pipe& p)
{
	std::cout << "You entered: " << p.length << std::endl;
};

Pipe NewPipe()
{
	Pipe p;
	p.id = 0;
	std::cout << "Enter length: ";
	std::cin >> p.length;
	return p;
};

int main()
{
	Pipe p = NewPipe();
	PrintPipe(p);
	return 0;
}
