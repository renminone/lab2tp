#include <iostream>
#include <iostream>
#include "task1.h"
#include "task2.h"

using namespace std;

void menuf()
{
	cout << "Меню: " << endl;
	cout << "1 - задание 1." << endl;
	cout << "2 - задание 2." << endl;
	cout << "0 - выход." << endl << endl;

	cout << "Ввести задание: ";
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int k = 1;
	int t;

	while (k != 0)
	{
		menuf();
		cin >> t;
		switch (t)
		{
		case 1: task1(); break;
		case 2: task2(); break;
		case 0: k = 0; break;
		}
	}
}
