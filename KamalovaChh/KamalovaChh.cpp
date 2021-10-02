#include <iostream>

using namespace std;

struct Pipe
{
	int id;
	int diametr;
	double length;
	bool InRepair = true;
};

struct CompressionStation
{
	int id = 0;
    string name;
	int NumberOfWorkshops;
	int NumberOfWorkshopsInOperation;
	double effiency;

};

Pipe NewPipe()
{
	Pipe p = {};
	cout << "Please, enter identifier: ";
	cin >> p.id;
	cout << "Please, enter diametr: ";
	cin >> p.diametr;
	cout << "Please, enter length: ";
	cin >> p.length;
	cout << "Is pipe in repair?";
	cin >> p.InRepair;
	return p;
};

void PrintPipe(const Pipe& p)
{
	cout << "Pipe identifier: " << p.id << endl;
	cout << "Pipe's diametr: " << p.diametr << endl;
	cout << "Pipe's length: " << p.length << endl;
	if (p.InRepair)
	{
		cout << "Pipe works" << endl;
	}
	else
	{
		cout << "Pipe does not work" << endl;
	}
	
}

int main()
{
	Pipe p = NewPipe();
	PrintPipe(p);
	return 0;
}
