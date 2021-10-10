#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <cstdlib>

using namespace std;

void Menu()
{
 cout   << "  1. Добавить трубу" << endl
		<< "  2. Добавить КС" << endl
		<< "  3. Просмотр всех объектов" << endl
		<< "  4. Редактировать трубу" << endl
		<< "  5. Редактировать КС" << endl
		<< "  6. Сохранить" << endl
		<< "  7. Загрузить" << endl
		<< "  0. Выход" << endl
		<< "  Выберите действие: ";
}

int GetCorrectNumber(int min, int max)
{
	int x;
	while((cin >> x).fail() || x<min || x>max)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Your choice. Please, type number (" << min << "-" << max << "): ";
	}
	return x;
}


struct Pipe
{
	int id;
	double diametr;
	double length;
	int InRepair;
};

struct CompressionStation
{
	int id;
    string name;
	int NumberOfWorkshops;
	int NumberOfWorkshopsInOperation;
	int effiency;
};

void LoadPipeCompSt( Pipe& p, CompressionStation& cs)
{
	ifstream filein;
	filein.open("data.txt", ios::in);
	filein >> p.id;
	filein >> p.diametr;
	filein >> p.length;
	filein >> p.InRepair;
	filein >> cs.id;
	filein.ignore(10000, '\n');
	string(cs.name);
	getline(filein, cs.name);
	filein >> cs.NumberOfWorkshops;
	filein >> cs.NumberOfWorkshopsInOperation;
	filein >> cs.effiency;
	filein.close();
}

void PrintPipeCompSt(Pipe& p, CompressionStation& cs)
{
	cout << "Pipe identifier: " << p.id << endl;
	cout << "Pipe's diametr: " << p.diametr << endl;
	cout << "Pipe's length: " << p.length << endl;
	if (p.InRepair == 1)
	{
		cout << "Pipe does not work" << endl;
	}
	if (p.InRepair == 2)
	{
		cout << "Pipe works" << endl;
	}
	cout << "Compression Station's identifier: " << cs.id << endl;
	cin.ignore(10000, '\n');
	cout << "Compression Station's name: " << cs.name << endl;
	cout << "Compression Station's number of workshops: " << cs.NumberOfWorkshops << endl;
	cout << "Compression Station's number of workshops in operation: " << cs.NumberOfWorkshopsInOperation << endl;
	cout << "Compression Station's effiency: " <<cs.effiency << endl;
}

void EditPipe(Pipe &p)
{
	if (p.InRepair == 1)
	{
		p.InRepair = 2;
    }
	else
	{
		p.InRepair = 1;
	}
}

void SavePipeCompSt(const Pipe& p, CompressionStation& cs)
{
	ofstream fileoutt;
	fileoutt.open("data.txt", ios::out);
	fileoutt << p.id << endl;
	fileoutt << p.diametr << endl;
	fileoutt << p.length << endl;
	fileoutt << p.InRepair << endl;
	fileoutt << cs.id << endl;
	fileoutt << cs.name << endl;
	fileoutt << cs.NumberOfWorkshops << endl;
	fileoutt << cs.NumberOfWorkshopsInOperation << endl;
	fileoutt.close();
}

void EditCompressionStation(CompressionStation& cs)
{
	cout << "Добавить цех или остановить один работающий? (1 - Добавить/ 2 - Остановить):  ";
	if (GetCorrectNumber(1,2) == 1 && (cs.NumberOfWorkshopsInOperation < cs.NumberOfWorkshops))
	{
		cout << cs.NumberOfWorkshopsInOperation++ << endl;
	}
	if (GetCorrectNumber(1,2) == 2 && (cs.NumberOfWorkshopsInOperation > 0))
	{
		cs.NumberOfWorkshopsInOperation--;
	}
	else
	{
		cout << "Редактирование невозможно";
	}

}

istream& operator >> (istream& in, Pipe& p)
{
	do
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Please, enter identifier: ";
		cin >> p.id;
	} while (cin.fail() || ((p.id < 0) && (p.id > 10000000)));

	do
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Please, enter diametr: ";
		cin >> p.diametr;
	} while (cin.fail() || ((p.diametr < 0) && (p.diametr > 10000000)));

	do
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Please, enter length: ";
		cin >> p.length;
	} while (cin.fail() || ((p.length < 0) && (p.length > 10000000)));

	do
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Is pipe in repair? (1 - Yes and 2 - No) ";
		cin >> p.InRepair;
	} while (cin.fail() || ((p.InRepair != 1) && (p.InRepair != 2)));
	return in;
}

istream& operator >> (istream& in, CompressionStation& cs)
{
	do
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Please, enter identifier: ";
		cin >> cs.id;
		cin.ignore(10000,'\n');
	} while (cin.fail() || ((cs.id < 0) && (cs.id > 10000000)));
	
	cout << "Please, enter name: ";
	string(cs.name);
	getline(cin, cs.name);

	do
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Please, enter number of workshops: ";
		cin >> cs.NumberOfWorkshops;
	} while (cin.fail() || ((cs.NumberOfWorkshops < 0) && (cs.NumberOfWorkshops > 10000000)));

	do
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Please, enter number of active workshops: ";
		cin >> cs.NumberOfWorkshopsInOperation;
	} while (cin.fail() || ((cs.NumberOfWorkshopsInOperation < 0) && (cs.NumberOfWorkshopsInOperation > 10000000)));

	do
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Please, point out effiency: ";
		cin >> cs.effiency;
	} while (cin.fail() || ((cs.effiency < 0) && (cs.effiency > 10000000)));

	return in;
}

ostream& operator << (ostream& out, const Pipe& p)
{
	out << "Pipe identifier: " << p.id << endl;
	out << "Pipe's diametr: " << p.diametr << endl;
	out << "Pipe's length: " << p.length << endl;
	if (p.InRepair == 1)
	{
		out << "Pipe does not work" << endl;
	}
	if (p.InRepair == 2)
	{
		out << "Pipe works" << endl;
	}
	else
	{
		out << "There is no data" << endl;
	}
	return out;
}

ostream& operator << (ostream& out, const CompressionStation& cs)
{
	out << "Compression Station's identifier: " << cs.id << endl;
	out << "Compression Station's name: " << cs.name << endl;
	out << "Compression Station's number of workshops: " << cs.NumberOfWorkshops << endl;
	out << "Compression Station's number of workshops in operation: " << cs.NumberOfWorkshopsInOperation << endl;
	out << "Compression Station's effiency: " << cs.effiency << endl;
	return out;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Pipe p = {};
	CompressionStation cs = {};
	while(1)
	{
		Menu();

		switch (GetCorrectNumber(0,7))
		{
		case 0:
			return 0;

		case 1:
			cin >> p;
			cout << "  " << endl;
			break;

		case 2:
			cout << "  " << endl;
			cin >> cs;
			cout << "  " << endl;
			break;

		case 3:
			cout << "  " << endl;
			cout << p;
			cout << "  " << endl;
			cout << cs;
			cout << "  " << endl;
			break;

		case 4:
			EditPipe(p);	
			cout << " " << endl;
			break;

		case 5:
			EditCompressionStation(cs);
			cout << " " << endl;
			break;

		case 6:
			cout << " " << endl;
			SavePipeCompSt(p,cs);
			break;

		case 7:
			cout << "  " << endl;
			//PrintPipe(LoadPipe());
			LoadPipeCompSt(p, cs);
			PrintPipeCompSt(p,cs);
			//PrintCompressionStation(LoadCompSt());
			cout << "  " << endl;
			break;

		default:
			cout << "Неправильно выбран пункт меню, попробуйте снова" << endl;
		}
	}
};
