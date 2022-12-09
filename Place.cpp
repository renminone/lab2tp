#include "Place.h"
#include <iostream>
using namespace std;

place::place(Note* n): ntp(n)
{
	cout << "Вызов конструктора класса Place." << endl;
	next = prev = nullptr;
}

place::place(const place& toCopy) :ntp(toCopy.ntp)
{
	cout << "Вызов конструктора копирования класса Place." << endl;
	next = prev = nullptr;
}

place::place(void)
{
	cout << "Вызов конструктора без параметров класса Place." << endl;
	ntp = nullptr;
	next = prev = nullptr;
}

place::~place()
{
	cout << "Вызов деструктора класса Place." << endl;
	delete ntp;
}
