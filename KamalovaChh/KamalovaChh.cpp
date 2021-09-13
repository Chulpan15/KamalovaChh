#include <iostream>
struct Pipe
{
	int id;
	double length;

};
void PrintPipe(Pipe& p)
{
	std::cout << "You entered" << p.length << std::endl;
}
Pipe NewPipe()
{
	Pipe p;
	p.id = 0;
	std::cout << "Enter length: ";
	std::cin >> p.length;
	return p;
}
int main()
{
	Pipe p = NewPipe();
	PrintPipe(p);
	return 0;
}
