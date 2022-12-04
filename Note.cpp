#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Note.h"

using namespace std;
using std::strcpy;

Note::Note() { }

Note::Note(char* s, char* n, int nu, int b[3])
{
	int i = 0;
	while (s[i] != ' ')
	{
		this->Surname[i] = s[i];
		i++;
	}
	i = 0;
	while (s[i] != ' ')
	{
		this->Name[i] = n[i];
		i++;
	}
	this->number = nu;
	for (i = 0; i < 3; i++) this->birthday[i] = b[i];
}

Note::Note(const Note& obj) { }

Note::~Note() { }

void Note::set()
{
	int size = 0;
	char r[100];
	char det = 'x';
	int i = 0;
	cout << "Введите фамилию: ";
	while(det != '_')
	{
		cin >> r[i];
		det = r[i];
		i++;
		size++;
	}
	Surname = new char[size];
	for (i = 0; i < size; i++)
	{
		if (r[i] != '_') Surname[i] = r[i];
		else Surname[i] = '\0';
	}
	cout << "Введите имя: ";
	i = 0;
	size = 0;
	det = 'x';
	while (det != '_')
	{
		cin >> r[i];
		det = r[i];
		i++;
		size++;
	}
	Name = new char[size];
	for (i = 0; i < size; i++)
	{
		if (r[i] != '_') Name[i] = r[i];
		else Name[i] = '\0';
	}
	cout << "Введите номер: ";
	cin >> number;
	cout << "Введите день рождения: ";
	cin >> birthday[0];
	cout << "Введите месяц рождения: ";
	cin >> birthday[1];
	cout << "Введите год рождения: ";
	cin >> birthday[2];
}

void Note::get()
{
	cout << Surname << " " << Name << " " << number << " ";
	for (int i = 0; i < 3; i++)
	{
		if (i != 2) cout << birthday[i] << "/";
		else cout << birthday[i] << endl;
	}
}

ostream& operator<<(ostream& stream, Note obj)
{
	stream << obj.Surname << " ";
	stream << obj.Name << " ";
	stream << obj.number << " ";
	stream << obj.birthday[0] << "/";
	stream << obj.birthday[1] << "/";
	stream << obj.birthday[2] << "\n";

	return stream;
}

istream& operator>>(istream& stream, Note& obj)
{
	stream >> obj.Surname;
	stream >> obj.Name;
	stream >> obj.number;
	stream >> obj.birthday[0];
	stream >> obj.birthday[1];
	stream >> obj.birthday[2];

	return stream;
}
