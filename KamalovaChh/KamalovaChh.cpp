#include <iostream>

using namespace std;

struct Pipe
{
	int id;
	int diametr;
	double length;
	int InRepair;
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
	do
	{
		cin.clear();
		cin.ignore(10000,'\n');
		cout << "Is pipe in repair? (1 - Yes and 0 - No) ";
		cin >> p.InRepair;
	}while (cin.fail() || ((p.InRepair != 1) && (p.InRepair != 0)));
	return p;
};

void PrintPipe(const Pipe& p)
{
	cout << "Pipe identifier: " << p.id << endl;
	cout << "Pipe's diametr: " << p.diametr << endl;
	cout << "Pipe's length: " << p.length << endl;
	if (p.InRepair == 1)
	{
		cout << "Pipe does not work" << endl;
	}
	else
	{
		cout << "Pipe works" << endl;
	}
};

int main()
{
	Pipe p = NewPipe();
	PrintPipe(p);
	return 0;
}
