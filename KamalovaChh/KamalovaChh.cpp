#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

int _stateMenu;
using namespace std;

void Menu()
{
	cout << "  Выберите действие" << endl
		 << "  Добавить трубу - 1" << endl
		 << "  Добавить КС - 2" << endl
		 << "  Просмотр всех объектов - 3" << endl
		 << "  Редактировать трубу - 4" << endl
		 << "  Редактировать КС - 5" << endl
		 << "  Сохранить - 6" << endl
		 << "  Загрузить - 7" << endl
		 << "  Выход - 0" << endl
		 << "  Ваш выбор";
	 cin >> _stateMenu;
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

Pipe LoadPipe()
{
	ifstream filein;
	filein.open("data.txt", ios::in);
	Pipe p;
	filein >> p.id;
	filein >> p.diametr;
	filein >> p.length;
	filein >> p.InRepair;
	filein.close();
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

CompressionStation CreateCompSt()
{
	CompressionStation cs = {};
	cout << "Please, enter identifier: ";
	cin >> cs.id;
	cout << "Please, enter name: ";
	cin >> cs.name;
	cout << "Please, enter number of workshops: ";
	cin >> cs.NumberOfWorkshops;
	cout << "Please, enter number of active workshops: ";
	cin >> cs.NumberOfWorkshopsInOperation;
	cout << "Please, point out effiency: ";
	cin >> cs.effiency;
	return cs;
};

CompressionStation LoadCompSt()
{
	ifstream fin;
	fin.open("data2.txt", ios::in);
	CompressionStation cs;
	fin >> cs.id;
	fin >> cs.name;
	fin >> cs.NumberOfWorkshops;
	fin >> cs.NumberOfWorkshopsInOperation;
	fin >> cs.effiency;
	fin.close();
	return cs;
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
	fout.open("data2.txt", ios::out);
	fout << "Compression Station's identifier: " << cs.id << endl;
	fout << "Compression Station's name: " << cs.name << endl;
	fout << "Compression Station's number of workshops: " << cs.NumberOfWorkshops << endl;
	fout << "Compression Station's number of workshops in operation: " << cs.NumberOfWorkshopsInOperation << endl;
	fout.close();
};

int main()
{
	//Pipe p = NewPipe();
	//CompressionStation cs = CreateCompSt();
	//PrintCompressionStation(cs);
	//PrintPipe(p);
	//SaveCompressionStation(cs);
	//SavePipe(p);
	//PrintPipe(LoadPipe());
	//PrintCompressionStation(LoadCompSt());
	//return 0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Menu();
	while (_stateMenu != 0)
	{
		switch (_stateMenu)
		{
		case 0:
			system("cls");

			system("cls");

		case 1:
			system("cls");

			system("cls");
			Menu();
			break;

		case 2:
			system("cls");

			system("pause");
			system("cls");
			Menu();
			break;

		case 3:
			system("cls");

			system("pause");
			system("cls");
			Menu();
			break;

		case 4:
			system("cls");

			system("pause");
			system("cls");
			Menu();
			break;

		case 5:
			system("cls");

			system("pause");
			system("cls");
			Menu();
			break;

		case 6:
			system("cls");

			system("pause");
			system("cls");
			Menu();
			break;

		case 7:
			system("cls");

			system("pause");
			system("cls");
			Menu();
			break;

		//default:
		//	system("pause");
		//	system("cls");
		//	cout « "Вы неправильно выбрали пункт в меню! " « endl;
		//	return 0;
		}
	}


};
