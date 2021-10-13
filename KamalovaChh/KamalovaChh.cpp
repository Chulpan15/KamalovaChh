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

int GetCorrectNumber(int min=0, int max= 10000000)
{
	int x;
	while((cin >> x).fail() || x<min || x>max)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Please, type number (" << min << "-" << max << "): ";
	}
	return x;
}

struct Pipe
{
	int id;
	int diametr;
	int length;
	bool InRepair = true;
};

struct CompressionStation
{
	int id;
    string name;
	int NumberOfWorkshops;
	int NumberOfWorkshopsInOperation;
	int effiency;
};

void LoadPipeCompSt( Pipe& p, CompressionStation& cs)//!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
{
	ifstream filein;
	filein.open("data.txt", ios::in);
	string text;
	filein >> text;
	if (text =="Pipe")
	{
		filein >> p.id;
		filein >> p.diametr;
		filein >> p.length;
		filein >> p.InRepair;
		filein >> text;
		if (text == "CompressionStation")
		{
			filein >> cs.id;
			filein.ignore(10000, '\n');
			getline(filein, cs.name);
			filein >> cs.NumberOfWorkshops;
			filein >> cs.NumberOfWorkshopsInOperation;
			filein >> cs.effiency;
		}
	}
	if (text == "CompressionStation")
	{
		filein >> cs.id;
		filein.ignore(10000, '\n');
		getline(filein, cs.name);
		filein >> cs.NumberOfWorkshops;
		filein >> cs.NumberOfWorkshopsInOperation;
		filein >> cs.effiency;
	}
	filein.close();
}

void PrintPipeCompSt(const Pipe& p, const CompressionStation& cs)//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
{
	if (p.id != 0)
	{
		cout << "Pipe identifier: " << p.id << endl;
		cout << "Pipe's diametr: " << p.diametr << endl;
		cout << "Pipe's length: " << p.length << endl;
		if (p.InRepair == 1)
		{
			cout << "Pipe does not work" << endl;
		}
		if (p.InRepair == 0)
		{
			cout << "Pipe works" << endl;
		}
	}
	if (cs.id != 0)
	{
		cout << "Compression Station's identifier: " << cs.id << endl;
		cout << "Compression Station's name: " << cs.name << endl;
		cout << "Compression Station's number of workshops: " << cs.NumberOfWorkshops << endl;
		cout << "Compression Station's number of workshops in operation: " << cs.NumberOfWorkshopsInOperation << endl;
		cout << "Compression Station's effiency: " << cs.effiency << endl;
	}
}

void EditPipe(Pipe &p)
{
	p.InRepair = !p.InRepair;
}

void SavePipeCompSt(const Pipe& p, const CompressionStation& cs)//!!!!!!!!!!!!!!!!!!!!! .........//Исправлено
{
	ofstream fileoutt;
	fileoutt.open("data.txt", ios::out);
	if (p.id != 0)
	{
		fileoutt << "Pipe" << endl;
		fileoutt << p.id << endl;
		fileoutt << p.diametr << endl;
		fileoutt << p.length << endl;
		fileoutt << p.InRepair << endl;
	}
	if (cs.id != 0)
	{
		fileoutt << "CompressionStation" << endl;
		fileoutt << cs.id << endl;
		fileoutt << cs.name << endl;
		fileoutt << cs.NumberOfWorkshops << endl;
		fileoutt << cs.NumberOfWorkshopsInOperation << endl;
		fileoutt << cs.effiency << endl;
	}
	fileoutt.close();
}

void EditCompressionStation(CompressionStation& cs)
{
	cout << "Добавить цех или остановить один работающий? (1 - Добавить/ 2 - Остановить):  ";
	int parametr;
	parametr = GetCorrectNumber(1, 2);
	if (parametr == 1 && (cs.NumberOfWorkshopsInOperation < cs.NumberOfWorkshops))//........//Исправлено
	{
		cout << cs.NumberOfWorkshopsInOperation++;
		return;
	}
	if (parametr == 2 && (cs.NumberOfWorkshopsInOperation > 0))
	{
		cs.NumberOfWorkshopsInOperation--;
		return;
	}
	cout << "Редактирование невозможно";
}

istream& operator >> (istream& in, Pipe& p)
{
	cout << "Please, enter identifier: ";
	p.id = GetCorrectNumber();
	cout << "Please, enter diametr: ";
	p.diametr = GetCorrectNumber();
	cout << "Please, enter length: ";
	p.length = GetCorrectNumber();
	cout << "Is pipe in repair? (1 - Yes and 0 - No) ";
	p.InRepair = GetCorrectNumber(0,1);
	return in;
}

istream& operator >> (istream& in, CompressionStation& cs)//~~~~~~~~~~~~~~~~~~~~~ //Исправлено
{
	cout << "Please, enter identifier: ";
	cs.id = GetCorrectNumber();
	cout << "Please, enter name: ";
	cin.ignore(10000, '\n');
    getline(cin, cs.name);
	cout << "Please, enter number of workshops: ";
	cs.NumberOfWorkshops = GetCorrectNumber();
	cout << "Please, enter number of active workshops: ";
	cs.NumberOfWorkshopsInOperation = GetCorrectNumber();
	cout << "Please, point out effiency: ";
	cs.effiency = GetCorrectNumber();
	return in;
}

ostream& operator << (ostream& out, const Pipe& p)//!!!!!!!!!!!!!!!!!! //Исправлено
{
	if (p.id != 0)
	{
		out << "Pipe identifier: " << p.id << endl;
		out << "Pipe's diametr: " << p.diametr << endl;
		out << "Pipe's length: " << p.length << endl;
		if (p.InRepair == 1)
		{
			out << "Pipe does not work" << endl;
		}
		if (p.InRepair == 0)
		{
			out << "Pipe works" << endl;
		}
	}
	return out;
}

ostream& operator << (ostream& out, const CompressionStation& cs)//????????????/ //Исправлено
{
	if (cs.id != 0)
	{
		out << "Compression Station's identifier: " << cs.id << endl;
		out << "Compression Station's name: " << cs.name << endl;
		out << "Compression Station's number of workshops: " << cs.NumberOfWorkshops << endl;
		out << "Compression Station's number of workshops in operation: " << cs.NumberOfWorkshopsInOperation << endl;
		out << "Compression Station's effiency: " << cs.effiency << endl;
	}
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
			EditCompressionStation(cs);//????????? 
			cout << " " << endl;
			break;

		case 6:
			cout << " " << endl;
			SavePipeCompSt(p,cs);
			break;

		case 7:
			cout << "  " << endl;
			LoadPipeCompSt(p, cs);
			PrintPipeCompSt(p,cs);
			cout << "  " << endl;
			break;

		default:
			cout << "Неправильно выбран пункт меню, попробуйте снова" << endl;
		}
	}
};
