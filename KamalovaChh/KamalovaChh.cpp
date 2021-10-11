#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <cstdlib>

using namespace std;

void Menu()
{
 cout   << "  1. �������� �����" << endl
		<< "  2. �������� ��" << endl
		<< "  3. �������� ���� ��������" << endl
		<< "  4. ������������� �����" << endl
		<< "  5. ������������� ��" << endl
		<< "  6. ���������" << endl
		<< "  7. ���������" << endl
		<< "  0. �����" << endl
		<< "  �������� ��������: ";
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

int Proverka()
{
	int y;
	do
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> y;
	} while (cin.fail() || ((y < 0) && (y > 10000000)));
	return y;
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

void LoadPipeCompSt( Pipe& p, CompressionStation& cs)//!!!!!!!!!!!!!!!!!!!!!!!!!!!! //����������
{
	ifstream filein;
	filein.open("data.txt", ios::in);
	if (p.id != 0)
	{
		filein >> p.id;
		filein >> p.diametr;
		filein >> p.length;
		filein >> p.InRepair;
	}
	if (cs.id != 0)
	{
		filein >> cs.id;
		filein.ignore(10000, '\n');
		string(cs.name);
		getline(filein, cs.name);
		filein >> cs.NumberOfWorkshops;
		filein >> cs.NumberOfWorkshopsInOperation;
		filein >> cs.effiency;
	}
	filein.close();
}

void PrintPipeCompSt(Pipe& p, CompressionStation& cs)//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! //����������
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
		cin.ignore(10000, '\n');
		cout << "Compression Station's name: " << cs.name << endl;
		cout << "Compression Station's number of workshops: " << cs.NumberOfWorkshops << endl;
		cout << "Compression Station's number of workshops in operation: " << cs.NumberOfWorkshopsInOperation << endl;
		cout << "Compression Station's effiency: " << cs.effiency << endl;
	}
	else
	{
		cout << "There is no data";
	}
}

void EditPipe(Pipe &p)
{
	p.InRepair = !p.InRepair;
}

void SavePipeCompSt(const Pipe& p, CompressionStation& cs)//!!!!!!!!!!!!!!!!!!!!! .........//����������
{
	ofstream fileoutt;
	fileoutt.open("data.txt", ios::out);
	if (p.id != 0)
	{
		fileoutt << "Pipe: " << endl;
		fileoutt << p.id << endl;
		fileoutt << p.diametr << endl;
		fileoutt << p.length << endl;
		fileoutt << p.InRepair << endl;
	}
	if (cs.id != 0)
	{
		fileoutt << "Compression Station: " << endl;
		fileoutt << cs.id << endl;
		fileoutt << cs.name << endl;
		fileoutt << cs.NumberOfWorkshops << endl;
		fileoutt << cs.NumberOfWorkshopsInOperation << endl;
	}
	fileoutt.close();
}

void EditCompressionStation(CompressionStation& cs)
{
	cout << "�������� ��� ��� ���������� ���� ����������? (1 - ��������/ 2 - ����������):  ";
	if (GetCorrectNumber(1,2) == 1 && (cs.NumberOfWorkshopsInOperation < cs.NumberOfWorkshops))//........// ����������
	{
		cout << cs.NumberOfWorkshopsInOperation++ << endl;
		return;
	}
	if (GetCorrectNumber(1,2) == 2 && (cs.NumberOfWorkshopsInOperation > 0))
	{
		cs.NumberOfWorkshopsInOperation--;
		return;
	}
	if ((cs.NumberOfWorkshopsInOperation = cs.NumberOfWorkshops) || (cs.NumberOfWorkshopsInOperation = 0 || cs.NumberOfWorkshopsInOperation < 0 || cs.NumberOfWorkshopsInOperation > cs.NumberOfWorkshops))
	{
		cout << "�������������� ����������";
	}

}

istream& operator >> (istream& in, Pipe& p)
{
	cout << "Please, enter identifier: ";
	Proverka();
	cout << "Please, enter diametr: ";
	Proverka();
	cout << "Please, enter length: ";
	Proverka();
	cout << "Is pipe in repair? (1 - Yes and 0 - No) ";
	Proverka();
	return in;
}

istream& operator >> (istream& in, CompressionStation& cs)//~~~~~~~~~~~~~~~~~~~~~ //����������
{
	cout << "Please, enter identifier: ";
	Proverka();
	cin.ignore(10000, '\n');
	cout << "Please, enter name: ";
	string();
	getline(cin, cs.name);
	cout << "Please, enter number of workshops: ";
	Proverka();
	cout << "Please, enter number of active workshops: ";
	Proverka();
	cout << "Please, point out effiency: ";
	Proverka();
	cout << "Please, point out effiency: ";
	Proverka();
	return in;
}

ostream& operator << (ostream& out, const Pipe& p)//!!!!!!!!!!!!!!!!!! //����������
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

ostream& operator << (ostream& out, const CompressionStation& cs)//????????????/ //����������
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
			cout << "����������� ������ ����� ����, ���������� �����" << endl;
		}
	}
};
