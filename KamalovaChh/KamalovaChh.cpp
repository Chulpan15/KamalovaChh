#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

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
	int diametr;
	double length;
	int InRepair;
};

struct CompressionStation
{
	int id;
    string name;
	int NumberOfWorkshops;
	int NumberOfWorkshopsInOperation;
	double effiency;
};

Pipe LoadPipe()
{
	ifstream filein;
	filein.open("data3.txt", ios::in);
	Pipe p;
	filein >> p.id;
	filein >> p.diametr;
	filein >> p.length;
	filein >> p.InRepair;
	filein.close();
	return p;
}

void EditPipe(Pipe &p)
{
	p.InRepair = (!p.InRepair);
}


void SavePipe(const Pipe& p)
{
	ofstream fileout;
	fileout.open("data.txt", ios::out);
	fileout << "Pipe identifier: " << p.id << endl;
	fileout << "Pipe's diametr: " << p.diametr << endl;
	fileout << "Pipe's length: " << p.length << endl;
	if (p.InRepair == 1)
	{
		fileout << "Pipe does not work" << endl;
	}
	else
	{
		fileout << "Pipe works" << endl;
	}
	fileout.close();
};

void SavePipe2(const Pipe& p)
{
	ofstream fileoutt;
	fileoutt.open("data3.txt", ios::out);
	fileoutt << p.id << endl;
	fileoutt << p.diametr << endl;
	fileoutt << p.length << endl;
	fileoutt << p.InRepair << endl;
	fileoutt.close();
}

CompressionStation LoadCompSt()
{
	CompressionStation cs;
	ifstream fin;
	fin.open("data2.txt", ios::in);
	fin >> cs.id;
	fin >> cs.name;
	fin >> cs.NumberOfWorkshops;
	fin >> cs.NumberOfWorkshopsInOperation;
	fin >> cs.effiency;
	fin.close();
	return cs;
};

void EditCompressionStation(CompressionStation& cs)
{
	string change;
	cout << "Добавить цех или запустить имеющиеся? (Добавить/Запустить) " << endl;

};

void PrintCompressionStation(const CompressionStation& cs)
{
	cout << "Compression Station's identifier: " << cs.id << endl;
	cout << "Compression Station's name: " << cs.name << endl;
	cout << "Compression Station's number of workshops: " << cs.NumberOfWorkshops << endl;
	cout << "Compression Station's number of workshops in operation: " << cs.NumberOfWorkshopsInOperation << endl;
};

void SaveCompressionStation(const CompressionStation& cs)
{
	ofstream fout;
	fout.open("data1.txt", ios::out);
	fout << "Compression Station's identifier: " << cs.id << endl;
	fout << "Compression Station's name: " << cs.name << endl;
	fout << "Compression Station's number of workshops: " << cs.NumberOfWorkshops << endl;
	fout << "Compression Station's number of workshops in operation: " << cs.NumberOfWorkshopsInOperation << endl;
	fout.close();
};

void SaveCompressionStation2(const CompressionStation& cs)
{
	ofstream foutt;
	foutt.open("data2.txt", ios::out);
	foutt << cs.id << endl;
	foutt << cs.name << endl;
	foutt << cs.NumberOfWorkshops << endl;
	foutt << cs.NumberOfWorkshopsInOperation << endl;
	foutt.close();
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
		cout << "Is pipe in repair? (1 - Yes and 0 - No) ";
		cin >> p.InRepair;
	} while (cin.fail() || ((p.InRepair != 1) && (p.InRepair != 0)));
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
	} while (cin.fail() || ((cs.id < 0) && (cs.id > 10000000)));

	cout << "Please, enter name: ";
	in >> cs.name;

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
ostream& operator << (ostream& out,const Pipe& p)
{
	out << "Pipe identifier: " << p.id << endl;
	out << "Pipe's diametr: " << p.diametr << endl;
	out << "Pipe's length: " << p.length << endl;
	if (p.InRepair == 1)
	{
		out << "Pipe does not work" << endl;
	}
	else
	{
		out << "Pipe works" << endl;
	}
	return out;
}

ostream& operator << (ostream& out, const CompressionStation& cs)
{
	out << "Compression Station's identifier: " << cs.id << endl;
	out << "Compression Station's name: " << cs.name << endl;
	out << "Compression Station's number of workshops: " << cs.NumberOfWorkshops << endl;
	out << "Compression Station's number of workshops in operation: " << cs.NumberOfWorkshopsInOperation << endl;
	return out;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Pipe p;
	CompressionStation cs;
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
			//PrintCompressionStation(cs);
			cout << cs;
			cout << "  " << endl;
			break;

		case 4:
			EditPipe(p);	
			break;

		case 5:
			break;

		case 6:
			SavePipe(p);
			SavePipe2(p);
			SaveCompressionStation(cs);
			SaveCompressionStation2(cs);
			break;

		case 7:
			cout << "  " << endl;
			//PrintPipe(LoadPipe());
			//PrintCompressionStation(LoadCompSt());
			cout << "  " << endl;
			break;

		default:
			cout << "Неправильно выбран пункт меню, попробуйте снова" << endl;
		}
	}
};
